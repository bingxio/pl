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
    "明",
    "刑",
    "朱",
    "金",
    "德",
    "白",
    "玉",
    "牢",
    "玄",
    "司",
    "勾",
]

D = [
    "建",
    "除",
    "满",
    "平",
    "定",
    "执",
    "破",
    "危",
    "成",
    "收",
    "开",
    "闭",
]

S = []

COUNT = 0
MAP = []


def gh(i: str) -> str:
    m = {
        "甲": "己",
        "乙": "庚",
        "丙": "辛",
        "丁": "壬",
        "戊": "癸",
        "己": "甲",
        "庚": "乙",
        "辛": "丙",
        "壬": "丁",
        "癸": "戊",
    }
    return m.get(i)


def zc(i: str) -> str:
    m = {
        "子": "午",
        "丑": "未",
        "寅": "申",
        "卯": "酉",
        "辰": "戌",
        "巳": "亥",
        "午": "子",
        "未": "丑",
        "申": "寅",
        "酉": "卯",
        "戌": "辰",
        "亥": "巳",
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

            result = [[], []]

            result[0].extend(" " * 4)
            result[1].extend(" " * 4)

            result[0][0] = gh(i[0])
            result[0][1] = j

            rev = A.index(p[0]) % 2 != 0
            z = zc(j)

            dp = []
            dp.extend(" " * 12)
            n = B.index(z)

            for nn in range(0, 12):
                dp[n] = C[nn]

                if not rev:
                    n += 1
                    if n == 12:
                        n = 0
                else:
                    n -= 1
                    if n == -1:
                        n = 11
            result[0][2] = dp[B.index(j)]
            result[1][2] = dp[B.index(i[1])]

            n = B.index(z)

            for nn in range(0, 12):
                dp[n] = D[nn]

                if not rev:
                    n += 1
                    if n == 12:
                        n = 0
                else:
                    n -= 1
                    if n == -1:
                        n = 11
            result[0][3] = dp[B.index(j)]
            result[1][3] = dp[B.index(i[1])]

            for m in H:
                if m[1] == j:
                    result[1][0] = m[0]
                    break
            result[1][1] = i[1]

            print(
                """
                        %s %s %s %s
                        %s %s %s %s
                """
                % (
                    result[0][0],
                    result[0][1],
                    result[0][2],
                    result[0][3],
                    result[1][0],
                    result[1][1],
                    result[1][2],
                    result[1][3],
                )
            )

            global COUNT

            for t in MAP:
                n = t[0]
                b = t[1]

                x = result[0]
                y = result[1]

                if (
                    n[0] == x[0]
                    and n[1] == x[1]
                    and n[2] == x[2]
                    and n[3] == x[3]
                    and b[0] == y[0]
                    and b[1] == y[1]
                    and b[2] == y[2]
                    and b[3] == y[3]
                ):
                    raise Exception("PANIC!!", COUNT)

            MAP.append(result)
            COUNT += 1
            # result = []
            # result.extend(" " * 4)

            # for m in H:
            #     if m[1] == j:
            #         result[0] = m[0]
            #         break
            # result[1] = gh(i[0])
            # result[2] = j
            # result[3] = i[1]

            # print(
            #     """
            #                 %s %s %s %s
            #     """
            #     % (
            #         result[0],
            #         result[1],
            #         result[2],
            #         result[3],
            #     )
            # )

            # global COUNT

            # for t in MAP:
            #     if (
            #         t[0] == result[0]
            #         and t[1] == result[1]
            #         and t[2] == result[2]
            #         and t[3] == result[3]
            #     ):
            #         raise Exception("PANIC!!", COUNT)

            # MAP.append(result)
            # COUNT += 1


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


print("Done!", COUNT, len(MAP))
