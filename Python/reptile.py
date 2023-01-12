from bs4 import BeautifulSoup
import requests as rq

URL = "https://jieqi.chazhi.net/"
YEAR = 2020
FILE = open("q", "w")


def parse(span):
    it = iter(span)
    next(it)

    j = 1

    while True:
        try:
            p = next(it).text
            p = p.strip()
            # print(p)

            m = p[0:2]
            d = p[3:5]

            h = p[7:9]
            s = p[10:12]

            # 此处判断
            # 原网站小雪节 月份显示错误
            # 需要手动改成 11 月
            if j == 20:
                FILE.write("\"11 %s %s %s\\n\"\n" % (d, h, s))
            else:
                FILE.write("\"%s %s %s %s\\n\"\n" % (m, d, h, s))
            j += 1
        except StopIteration:
            break


for i in range(0, 80):
# for i in range(0, 1):
    rp = rq.get("%s%s" % (URL, YEAR))
    print("(%d) : %d --> %d => OK" % (i + 1, YEAR, rp.status_code))

    soup = BeautifulSoup(rp.text, "html.parser")
    tb = soup.select("table td")

    FILE.write("\"%s\"\n" % YEAR)
    parse(tb)

    YEAR += 1

FILE.close()
