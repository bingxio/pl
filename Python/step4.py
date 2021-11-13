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

S = []


COUNT = 0
MAP = []

F = [
    ["子", "午", "卯", "酉"],
    ["辰", "戌", "丑", "未"],
    ["寅", "申", "巳", "亥"],
]


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

            result = []
            result.extend(" " * 4)

            result[2] = j
            result[3] = i[1]

            b = B.index(p[1])

            x, y = [], []
            c = 2
            rev = i[1] in [
                "酉",
                "戌",
                "亥",
                "子",
                "丑",
                "寅",
            ]

            for _ in range(0, 12):
                x.append(B[c])
                y.append(B[b])

                c += 1

                if c == 12:
                    c = 0
                if rev:
                    b -= 1

                    if b == -1:
                        b = 11
                else:
                    b += 1

                    if b == 12:
                        b = 0

            result[1] = x[y.index(j)]

            t = ""

            if p[1] in F[0]:
                t = result[3]

            if p[1] in F[1]:
                t = result[2]

            if p[1] in F[2]:
                t = result[1]

            # a, b = A.index(p[0]), B.index(p[1])
            # x, y = a, b - a

            # if y < 0:
            #     y += 12

            # for _ in range(0, 12):
            #     if B[y] == t:
            #         result[0] = A[x]
            #         break

            #     x += 1
            #     y += 1

            #     if x == 10:
            #         x = 0
            #     if y == 12:
            #         y = 0
            for n in H:
                if n[1] == t:
                    result[0] = n[0]
                    break

            print(
                """
                        %s
                        %s
                        %s
                        %s
                """
                % (
                    result[0],
                    result[1],
                    result[2],
                    result[3],
                )
            )

            for u in MAP:
                l = u[1]
                if (
                    l[0] == result[0]
                    and l[1] == result[1]
                    and l[2] == result[2]
                    and l[3] == result[3]
                ):
                    raise Exception("PANIC!!", result, u[0])

            MAP.append(["%s %s --> %s" % (p, i, j), result])

            global COUNT
            COUNT += 1


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
    # eval("丙子")


print("局数：", COUNT, len(MAP))
