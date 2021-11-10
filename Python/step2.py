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

L = ["青", "朱", "勾", "蛇", "白", "玄"]

S = []

COUNT = 0
MAP = []


def gh(i: str) -> int:
    m = {
        "甲": 5,
        "乙": 6,
        "丙": 7,
        "丁": 8,
        "戊": 9,
        "己": 0,
        "庚": 1,
        "辛": 2,
        "壬": 3,
        "癸": 4,
    }
    return m.get(i)


def fl(i: str) -> int:
    if i == "甲" or i == "乙":
        return 0
    if i == "丙" or i == "丁":
        return 1
    if i == "戊":
        return 2
    if i == "己":
        return 3
    if i == "庚" or i == "辛":
        return 4
    if i == "壬" or i == "癸":
        return 5


RA = [
    "子",
    "申",
    "卯",
    "巳",
    ["辰", "戌", "丑", "未"],
    "亥",
    "酉",
    "寅",
    "午",
]


def get_position(i: int) -> int:
    m = {
        "子": 0,
        "丑": 4,
        "寅": 7,
        "卯": 2,
        "辰": 4,
        "巳": 3,
        "午": 8,
        "未": 4,
        "申": 1,
        "酉": 4,
        "戌": 4,
        "亥": 5,
    }
    return m.get(i)


def stringer(R1, R2, R3):
    print(
        """               
                          %s          %s          %s
                        4 %s %s     9 %s %s     2 %s %s
                          巳          午          申

                          %s          %s          %s
                        3 %s %s     5 %s %s     7 %s %s
                          卯          墓          酉

                          %s          %s          %s
                        8 %s %s     1 %s %s     6 %s %s
                          寅          子          亥
        """
        % (
            R2[3],
            R2[8],
            R2[1],
            #
            R1[3],
            R3[3],
            R1[8],
            R3[8],
            R1[1],
            R3[1],
            #
            R2[2],
            R2[4],
            R2[6],
            #
            R1[2],
            R3[2],
            R1[4],
            R3[4],
            R1[6],
            R3[6],
            #
            R2[7],
            R2[0],
            R2[5],
            #
            R1[7],
            R3[7],
            R1[0],
            R3[0],
            R1[5],
            R3[5],
        )
    )


def add(R1, R2, R3):
    MAP.append([])


def valid():
    pass


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

            rev = A.index(p[0]) % 2 != 0

            # 应转时支
            R1 = []
            R1.extend(" " * 9)

            ji = get_position(i[1])
            pi = B.index(j)

            for _ in range(0, 9):
                R1[ji] = B[pi]

                if rev:
                    ji -= 1
                    if ji == -1:
                        ji = 8
                else:
                    ji += 1
                    if ji == 9:
                        ji = 0
                pi += 1
                if pi == 12:
                    pi = 0

            # 干合转支
            R2 = []
            R2.extend(" " * 9)

            ji = get_position(j)
            gi = gh(i[0])

            for _ in range(0, 9):
                R2[ji] = A[gi]

                if rev:
                    ji -= 1
                    if ji == -1:
                        ji = 8
                else:
                    ji += 1
                    if ji == 9:
                        ji = 0
                gi += 1
                if gi == 10:
                    gi = 0

            # 日辰六神
            R3 = []
            R3.extend(" " * 9)

            ji = get_position(j)
            ai = fl(p[0])

            for _ in range(0, 9):
                R3[ji] = L[ai]

                if rev:
                    ji -= 1
                    if ji == -1:
                        ji = 8
                else:
                    ji += 1
                    if ji == 9:
                        ji = 0
                ai += 1
                if ai == 6:
                    ai = 0

            stringer(R1, R2, R3)

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

    # for i in S:
    # eval(i)
    eval(input())
#    eval("庚申")


print("Done!", COUNT, len(MAP))
