#include "nl.h"

#include "nd.h"

// 返回闰哪个月 没有闰月则返回0
int leap_month(int year) { return info[year - 1900] & 0xf; }

// 返回农历年闰月的天数 该年没有闰月则返回0
int leap_days(int year) {
  if (0 != leap_month(year)) {
    return (0 != (info[year - 1900] & 0x10000) ? 30 : 29);
  }
  return 0;
}

// 返回整年的天数
int nyear_days(int year) {
  int i, sum = 348;

  for (i = 0x8000; i > 0x8; i >>= 1) {
    sum += (0 != (info[year - 1900] & i) ? 1 : 0);
  }
  return sum + leap_days(year);
}

// 返回月（非闰月）的总天数
int month_days(int year, int month) {
  return (0 != (info[year - 1900] & (0x10000 >> month)) ? 30 : 29);
}

/* 算法解析
该算法总体思想是计算给定日期到 0年3月1日 的天数，然后相减，获取天数的间隔。

m1 = (month_start + 9) % 12;
用于判断日期是否大于3月（2月是判断闰年的标识），还用于记录到3月的间隔月数。

y1 = year_start - m1/10;
如果是1月和2月，则不包括当前年（因为是计算到0年3月1日的天数）。

d1 = 365*y1 + y1/4 - y1/100 + y1/400 + (m1*306 + 5)/10 + (day_start - 1);
其中 365*y1 是不算闰年多出那一天的天数，

y1/4 - y1/100 + y1/400 是加所有闰年多出的那一天，

(m2*306 + 5)/10
用于计算到当前月到3月1日间的天数，306=365-31-28（1月和2月），5是全年中不是31天月份的个数

(day_start - 1) 用于计算当前日到1日的间隔天数。 */
int day_diff(ntime start, ntime end) {
  int y2, m2, d2;
  int y1, m1, d1;

  m1 = (start.month + 9) % 12;
  y1 = start.year - m1 / 10;
  d1 = 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 + (m1 * 306 + 5) / 10 +
       (start.day - 1);

  m2 = (end.month + 9) % 12;
  y2 = end.year - m2 / 10;
  d2 = 365 * y2 + y2 / 4 - y2 / 100 + y2 / 400 + (m2 * 306 + 5) / 10 +
       (end.day - 1);

  return d2 - d1;
}

// 公历换算农历
// 1900.1.31 - 2100.12.31
ntime nl(int year, int month, int day) {
  // 间隔天数
  int offset = day_diff(ntime(1900, 1, 31, -1), ntime(year, month, day, -1));
  int i, temp = 0;

  for (i = 1900; i < 2101 && offset > 0; i++) {
    temp = nyear_days(i);
    offset -= temp;
  }
  if (offset < 0) {
    offset += temp;
    i--;
  }

  year = i;
  int leap = leap_month(i);  // 闰哪个月
  bool is_leap = false;

  // 效验闰月
  for (i = 1; i < 13 && offset > 0; i++) {
    // 闰月
    if (leap > 0 && i == (leap + 1) && is_leap == false) {
      --i;
      is_leap = true;
      temp = leap_days(year);  // 闰月天数
    } else {
      temp = month_days(year, i);  // 普通月天数
    }
    // 解除闰月
    if (is_leap && i == (leap + 1)) {
      is_leap = false;
    }
    offset -= temp;
  }

  // 闰月导致数组下标重叠取反
  if (offset == 0 && leap > 0 && i == leap + 1) {
    // if (is_leap) {
    //   is_leap = false;
    // } else {
    //   is_leap = true;
    //   --i;
    // }
    if (!is_leap) i--;
  }
  if (offset < 0) {
    offset += temp;
    i--;
  }
  month = i;
  day = offset + 1;
  return ntime(year, month, day, temp);
}
