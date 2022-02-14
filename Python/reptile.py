"""
    @title      获取 1980 年到 2080 年的 24 节气交节时间
    @author     bingxio, 丙杺
    @email      bingxio@qq.com
    @date       2021-10-25 23:16:12
"""

from typing import List, Tuple
from bs4 import BeautifulSoup

import requests as rq

from api import get_wnl

URL = "http://jieqi.ttcha.net/"
YEAR = 1980
Y = "庚申"

FILE = open("2080.txt", "w")

A = [
    "甲",
    "乙",
    "丙",
    "丁",
    "戊",
    "己",
    "庚",
    "辛",
    "壬",
    "癸",
]

B = [
    "子",
    "丑",
    "寅",
    "卯",
    "辰",
    "巳",
    "午",
    "未",
    "申",
    "酉",
    "戌",
    "亥",
]


def next(p: str) -> str:
    a = A.index(p[0])
    b = B.index(p[1])

    a += 1
    b += 1

    if a == 10:
        a = 0
    if b == 12:
        b = 0

    return A[a] + B[b]


def wfile(result) -> None:
    for i in result:
        # FILE.write("%s %s\n" % (i[0], i[1]))
        # print(i, end="")
        FILE.write("%s\n" % str(i))


def parse(span) -> List[Tuple[str, str]]:
    global Y

    pos = 0

    i, p = 0, 2
    r = ["%d %s" % (YEAR, Y)]

    Y = next(Y)

    while pos < 24:
        name = span[i].text
        date = span[p].text

        if name == "立秋":
            r.append("")

        if (pos + 1) % 2 == 0:
            date = "%s 日 %s" % (date[8:10], date[11:])
            r.append("          %s %s" % (name, date))
        else:
            date = "%s 月 %s 日 %s" % (date[5:7], date[8:10], date[11:])
            r.append("%s %s" % (name, date))

        i = p + 1
        p += 3
        pos += 1

    r.append("")

    for i in range(1, 13):
        m = [
            "1   月",
            "2   月",
            "3   月",
            "4   月",
            "5   月",
            "6   月",
            "7   月",
            "8   月",
            "9   月",
            "10  月",
            "11  月",
            "12  月",
        ][i - 1]

        if i == 7:
            r.append("")

        a = get_wnl(YEAR, i, 1)
        b = get_wnl(YEAR, i, 10)
        c = get_wnl(YEAR, i, 20)

        s = """%s   1 日 %s    %s %s
      10 %s %s 20 %s %s""" % (
            m,
            a[0],
            a[1],
            a[2],
            b[1],
            b[2],
            c[1],
            c[2],
        )
        r.append(s)

    return r


for i in range(0, 120):
    # for i in range(0, 5):
    rp = rq.get("%s%s.html" % (URL, YEAR))
    print("(%d) : %d --> %d => OK" % (i + 1, YEAR, rp.status_code))

    soup = BeautifulSoup(rp.text, "html.parser")
    span = soup.select("ul span")

    result = parse(span)
    wfile(result)

    YEAR += 1

FILE.close()
print("Done!")
