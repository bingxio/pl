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

C = [
    "青",
    "六",
    "勾",
    "蛇",
    "朱",
    "常",
    "白",
    "阴",
    "空",
    "后",
    "玄",
    "贵",
]

S = []


COUNT = 0
MAP = []

F = [
    ["寅", "申", "巳", "亥"],
    ["子", "午", "卯", "酉"],
    ["辰", "戌", "丑", "未"],
]


def gc(i: str) -> int:
    m = {
        "子": 6,
        "丑": 7,
        "寅": 8,
        "卯": 9,
        "辰": 10,
        "巳": 11,
        "午": 0,
        "未": 1,
        "申": 2,
        "酉": 3,
        "戌": 4,
        "亥": 5,
    }
    return m.get(i)


def gh(i: str) -> int:
    m = {
        "子": 1,
        "丑": 0,
        "寅": 11,
        "亥": 2,
        "卯": 10,
        "戌": 3,
        "辰": 9,
        "酉": 4,
        "巳": 8,
        "申": 5,
        "午": 7,
        "未": 6,
    }
    return m.get(i)


def eval(p: str):
    print(p)

    dt = p[0]
    ht = 0

    if dt in ["甲", "己"]:
        ht = 0

    if dt in ["乙", "庚"]:
        ht = 2

    if dt in ["丙", "辛"]:
        ht = 4

    if dt in ["丁", "壬"]:
        ht = 6

    if dt in ["戊", "癸"]:
        ht = 8

    H = []

    for i in range(0, 12):
        H.append("%s%s" % (A[ht], B[i]))

        ht += 1

        if ht == 10:
            ht = 0

    for i in H:
        print("\t", i)

        for j in B:
            print("\t\t", j)

            S1 = []
            S1.extend(" " * 12)

            a = B.index(j)
            b = B.index(i[1])

            for _ in range(0, 12):
                S1[b] = B[a]

                a += 1
                b += 1

                if a == 12:
                    a = 0
                if b == 12:
                    b = 0

            el = []
            dc = False

            for f in F:
                if p[1] in f:
                    if A.index(p[0]) % 2 == 0:
                        el.extend(f[:2])
                        dc = True
                    else:
                        el.extend(f[2:])
                    break

            god = ""
            rev = False

            if i[1] in ["卯", "辰", "巳", "午", "未", "申"]:
                god = el[0]

            if i[1] in ["酉", "戌", "亥", "子", "丑", "寅"]:
                god = el[1]
                rev = True

            S2 = []
            S2.extend(" " * 12)

            a = S1.index(god)

            for l in range(0, 12):
                S2[a] = C[l]

                if rev:
                    a -= 1
                    if a == -1:
                        a = 11
                else:
                    a += 1
                    if a == 12:
                        a = 0

            t = 0

            if dc:
                t = gc(god)
            else:
                t = gh(god)

            S3 = []
            S3.extend(" " * 12)

            a = S1.index(B[t])
            b = 0

            for _ in range(0, 12):
                S3[a] = A[b]

                b += 1
                if b == 10:
                    b = 0
                a += 1
                if a == 12:
                    a = 0

            print(el, god, rev, B[t])
            print(S1)
            print(S2)
            print(S3)

            global COUNT
            COUNT += 1

            class Have():
                _

            for m in MAP:
                try:
                    for n in range(0, 12):
                        x, y, z = m[1], m[2], m[3]

                        if x[n] == S1[n] and y[n] == S2[n] and z[n] == S3[n]:
                            raise Have()
                except:
                    COUNT -= 1
                    break

            MAP.extend([["%s %s %s" % (p, i, j), S1, S2, S3]])


if __name__ == "__main__":
    a = 0
    b = 0

    for i in range(0, 60):
        S.append("%s%s" % (A[a], B[b]))

        a += 1
        b += 1

        if a == 10:
            a = 0
        if b == 12:
            b = 0

    for i in S:
        eval(i)
    # eval(input())
#    eval("庚申")


print("局数：", COUNT, len(MAP))
