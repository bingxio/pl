//
//    大六壬宗门九课
//
// 丙杺
// 2022 年 02 月 10 日

// ignore_for_file: non_constant_identifier_names, constant_identifier_names
// ignore_for_file: avoid_function_literals_in_foreach_calls
// ignore_for_file: prefer_function_declarations_over_variables

import 'dart:io';

enum F {
  A, // 木
  B, // 火
  C, // 土
  D, // 金
  E, // 水
}

List A = ["甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"];
List B = ["子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"];

final List PALACE = [2, 3, 5, 6, 1, 7, 8, 9, 11, 0]; // 寄宫
// final List PALACE = [2, 4, 5, 7, 5, 7, 8, 10, 11, 1];

final List AF = [
  F.A,
  F.A,
  F.B,
  F.B,
  F.C,
  F.C,
  F.D,
  F.D,
  F.E,
  F.E,
]; // 天干五行

final List BF = [
  F.E,
  F.C,
  F.A,
  F.A,
  F.C,
  F.B,
  F.B,
  F.C,
  F.D,
  F.D,
  F.C,
  F.E,
]; // 地支五行

final Map KE = {
  F.A: F.C,
  F.B: F.D,
  F.C: F.E,
  F.D: F.A,
  F.E: F.B,
}; // 五行相克

// 地支相刑
final Map XIN = {
  "子": "卯",
  "卯": "子", // 1
  "丑": "戌",
  "戌": "未",
  "未": "丑", // 2
  "巳": "申",
  "申": "寅",
  "寅": "巳", // 3
  // 自刑
  "辰": "辰",
  "午": "午",
  "酉": "酉",
  "亥": "亥", // 4
};

// 地支对冲
final Map CHO = {
  "子": "午",
  "丑": "未",
  "寅": "申",
  "卯": "酉",
  "辰": "戌",
  "巳": "亥",
  //
  "午": "子",
  "未": "丑",
  "申": "寅",
  "酉": "卯",
  "戌": "辰",
  "亥": "巳",
};

// 天干相合
final Map GH = {
  "甲": "己",
  "乙": "庚",
  "丙": "辛",
  "丁": "壬",
  "戊": "癸",
  //
  "己": "甲",
  "庚": "乙",
  "辛": "丙",
  "壬": "丁",
  "癸": "戊",
};

// 四课转换五行
List transClToF(List cl) {
  List top = [];
  List bottom = [];

  for (int i = 0; i < 4; i++) {
    int x = B.indexOf(cl[0][i]);
    int y = B.indexOf(cl[1][i]);

    top.add(BF[x]); // 天盘

    // 日干
    if (y == -1) {
      y = A.indexOf(cl[1][i]);
      bottom.add(AF[y]);
    } else {
      bottom.add(BF[y]); // 地盘
    }
  }

  /* -------------- 转五行 ------------- */

  return [top, bottom];
}

// 生成十二天盘
List genTp() {
  List result = [];

  for (int i = 0; i < 12; i++) {
    List item = List.generate(12, (_) => "");
    int j = i, index = 0;

    while (index < 12) {
      item[j] = B[index];

      index++;
      j++;
      if (j == 12) j = 0;
    }
    result.add(item);
  }
  return result;
}

// 根据干支和天盘生成四课
List genCl(List tp, String day) {
  print("$day\n");

  tp.forEach((x) => stdout.write("$x "));
  print("");

  B.forEach((x) => stdout.write("$x "));
  print("\n");

  /* -------------- 调试 ------------- */

  List result = List.generate(
    2,
    (_) => List.generate(4, (_) => ""),
  );

  result[1][3] = day[0]; // 干
  result[1][1] = day[1]; // 支

  int gA = PALACE[A.indexOf(day[0])];

  result[0][3] = tp[gA]; // 干阳
  result[1][2] = tp[gA]; // 干阴
  result[0][2] = tp[B.indexOf(result[1][2])]; // 干阴

  int gB = B.indexOf(day[1]);

  result[0][1] = tp[gB]; // 支阳
  result[1][0] = tp[gB]; // 支阴

  result[0][0] = tp[B.indexOf(result[1][0])]; // 支阴

  result.add(B[gA]); // 寄支

  /* -------------- 四课 ------------- */

  print("""
      ${(result[0] as List).join("  ")}
      ${(result[1] as List).join("  ")}（${B[gA]}）
""");
  return result;
}

// 地支阴阳
bool checkYY(String zhi) => B.indexOf(zhi) % 2 == 0;

// 主体计算
List eval(List tp, List cl) {
  List tr = transClToF(cl); // 四课五行
  bool yang = A.indexOf(cl[1][3]) % 2 == 0; // 阳日阴日

  String gan = cl[1][3]; // 日干
  String zhi = cl[1][1]; // 日支

  List result = [];

  if (tp[0] == "子") {
    result.add("伏吟");

    var a = cl[0][yang ? 3 : 1]; // 阳日，干上作初；阴日，支上作初
    result.add(a);

    var b = XIN[a]; // 中取初刑
    if (b == a) {
      b = CHO[a]; // 自刑取冲
    }

    var c = XIN[b];
    if (c == b) {
      c = CHO[b];
    }

    result.add(b);
    result.add(c);

    return result;
  }

  /* -------------- 伏吟 ------------- */

  if (tp[0] == "午") {
    result.add("反吟");

    if (zhi == "巳" || zhi == "酉" || zhi == "丑") result.add("亥"); // 初取日支驿马
    if (zhi == "亥" || zhi == "卯" || zhi == "未") result.add("巳");
    if (zhi == "寅" || zhi == "午" || zhi == "戌") result.add("申");
    if (zhi == "申" || zhi == "子" || zhi == "辰") result.add("寅");

    result.add(cl[0][1]); // 中取支上
    result.add(cl[0][3]); // 末取干上

    return result;
  }

  /* -------------- 反吟 ------------- */

  List format = [
    "${cl[0][0]}${cl[1][0]}", // 4
    "${cl[0][1]}${cl[1][1]}", // 3
    "${cl[0][2]}${cl[1][2]}", // 2
    "${cl[0][3]}${cl[2]}", // 替换为日干寄宫
  ];
  List mapping = [
    [1, 2, 3],
    [0, 2, 3],
    [0, 1, 3],
    [0, 1, 2]
  ];

  Map numbers = {}; // 重复的干支

  for (int i = 0; i < 4; i++) {
    var current = format[i];
    var p = 0;

    // 挨个映射比较
    for (int k = 0; k < 3; k++) {
      int index = mapping[i][k];

      // 自己
      if (index == i) continue;
      if (current == format[index]) {
        p++;
      }
    }
    if (p != 0) numbers[current] = p;
  }

  if (numbers.length == 1) {
    result.add("别责");

    if (yang) {
      var gh = GH[gan];
      var dp = PALACE[A.indexOf(gh)]; // 阳日取干合上神作初

      result.add(tp[dp]);

      result.add(cl[0][3]);
      result.add(cl[0][3]); // 中末干上
    } else {
      List sh = ["寅午戌", "申子辰", "巳酉丑", "亥卯未"]; // 阴日取三合前辰作初

      for (int i = 0; i < 4; i++) {
        String item = sh[i];

        if (item.contains(cl[1][1])) {
          int p = item.indexOf(zhi);

          p += 1;
          if (p == 3) {
            p = 0;
          }

          result.add(item[p]);
          break;
        }
      }

      result.add(cl[0][3]);
      result.add(cl[0][3]); // 中末干上
    }

    return result;
  }

  /* -------------- 别责 ------------- */

  if (numbers.length == 2) {
    result.add("八专");

    late int index;

    if (yang) {
      index = B.indexOf(cl[0][3]) + 3; // 阳日，干上顺三位

      if (index >= 12) {
        index -= 12;
      }
    } else {
      index = B.indexOf(cl[0][1]) - 3; // 阴日，支上逆三位

      if (index < 0) {
        index += 12;
      }
    }

    result.add(B[index]);

    result.add(cl[0][3]);
    result.add(cl[0][3]); // 中末干上

    return result;
  }

  /* -------------- 八专 ------------- */

  List zS = [], kX = []; // 贼上，克下

  for (int i = 0; i < 4; i++) {
    F a = tr[1][i];
    F b = tr[0][i];

    if (KE[a] == b) {
      zS.add(cl[0][i]); // 贼上
    }
    if (KE[b] == a) {
      kX.add(cl[0][i]); // 克下
    }
  }

  // 根据初传拉中末
  final Function simple = (String first) {
    result.add(first);

    result.add(tp[B.indexOf(result[1])]);
    result.add(tp[B.indexOf(result[2])]);
  };
  // 下贼上克，根据日干找阴阳
  final Function getYYZhi = (List element) {
    List d = [];

    element.forEach((item) {
      // 阳日
      if (yang && checkYY(item)) {
        d.add(item);
      }
      // 阴日
      if (!yang && !checkYY(item)) {
        d.add(item);
      }
    });

    return d;
  };

  List sheHaiArr = []; // 是否涉害

  if (zS.isNotEmpty) {
    // 单个贼克
    if (zS.length == 1) {
      result.add("贼克");

      simple(zS[0]);
      return result;
      /* -------------- 贼上 ------------- */

    } else {
      // 多个贼克
      List d = getYYZhi(zS); // 日干相同的支

      if (d.length == 1) {
        result.add("比用");

        simple(d[0]);
        return result;
        /* -------------- 比用 ------------- */

      } else {
        sheHaiArr = d;
      }
    }
  }

  if (kX.isNotEmpty && sheHaiArr.isEmpty) {
    // 单个克下
    if (kX.length == 1) {
      result.add("贼克");

      simple(kX[0]);
      return result;
      /* -------------- 克下 ------------- */

    } else {
      // 多个克下
      List d = getYYZhi(kX); // 日干相同的支

      if (d.length == 1) {
        result.add("比用");

        simple(d[0]);
        return result;
        /* -------------- 比用 ------------- */

      } else {
        sheHaiArr = d;
      }
    }
  }

  if (sheHaiArr.isNotEmpty) {
    result.add("涉害");

    List<List> item = [[], [], []]; // 分孟仲季

    for (int i = 0; i < sheHaiArr.length; i++) {
      int index = tp.indexOf(sheHaiArr[i]);

      if ([2, 5, 8, 11].contains(index)) item[0].add(sheHaiArr[i]); // 孟
      if ([0, 3, 6, 9].contains(index)) item[1].add(sheHaiArr[i]); // 仲
      if ([1, 4, 7, 10].contains(index)) item[2].add(sheHaiArr[i]); // 季
    }

    // 孟地
    if (item[0].isNotEmpty) {
      if (item[0].length == 1) {
        simple(item[0].first); // 一个孟地
      } else {
        simple(cl[0][3]); // 多个孟神，干上作初
      }
    } else if (item[1].isNotEmpty) {
      // 仲地
      simple(item[1].first);
    } else if (item[2].isNotEmpty) {
      // 季地
      simple(item[2].first);
    }

    return result;
    /* -------------- 涉害 ------------- */

  }

  List item = [];

  for (int i = 0; i < 3; i++) {
    F title = tr[0][i]; // 先取克日干

    if (KE[title] == tr[1][3]) {
      item.add(cl[0][i]);
    }
  }

  if (item.isEmpty) {
    for (int i = 0; i < 3; i++) {
      F title = tr[0][i]; // 再取日干克上神

      if (KE[tr[1][3]] == title) {
        item.add(cl[0][i]);
      }
    }
  }

  if (item.length == 1) {
    result.add("遥克");

    simple(item[0]);
    return result;
  }

  if (item.length > 1) {
    result.add("遥克");

    List d = getYYZhi(item); // 阳日用阳，阴用阴
    // print(item);

    simple(d[0]);
    return result;
  }

  if (item.isEmpty) {
    result.add("昴星");

    if (yang) {
      result.add(tp[9]); // 阳日，酉上神

      result.add(cl[0][1]); // 中取支上
      result.add(cl[0][3]); // 末取干上
    } else {
      result.add(B[tp.indexOf("酉")]); // 阴日，酉下神

      result.add(cl[0][3]); // 中取干上
      result.add(cl[0][1]); // 末取支上
    }

    return result;
  }

  /* -------------- 昴星 ------------- */

  return result;
}

Map statis = {
  "贼克": 0,
  "比用": 0,
  "涉害": 0,
  "遥克": 0,
  "昴星": 0,
  "别责": 0,
  "八专": 0,
  "伏吟": 0,
  "反吟": 0
};

int count = 0;

void main() {
  List tp = genTp();

  int a = 0, b = 0;

  for (int i = 0; i < 60; i++) {
    String jz = "${A[a]}${B[b]}";

    tp.forEach((x) {
      List cl = genCl(x, jz);
      List result = eval(x, cl);

      print("""
      ${result[0]}
            ${result[1]}
            ${result[2]}
            ${result[3]}
      """);

      statis[result[0]] += 1;
      count += 1;
    });

    a++;
    b++;

    if (a == 10) a = 0;
    if (b == 12) b = 0;
  }

  print(statis);
}
