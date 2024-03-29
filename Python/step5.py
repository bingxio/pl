import random

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

#R = "32,13,21,11,22,33,23,31,12"
R = [[3, 2], [1, 3], [2, 1], [1, 1], [2, 2], [3, 3], [2, 3], [3, 1], [1, 2]]
RP = {
    "子": 0,
    "丑": 7,
    "寅": 7,
    "卯": 2,
    "辰": 3,
    "巳": 3,
    "午": 8,
    "未": 1,
    "申": 1,
    "酉": 6,
    "戌": 5,
    "亥": 5,
}
M = [
    [[],[],[]],
    [[],[],[]],
    [[],[],[]],
]

if __name__ == "__main__":
    a = 0
    b = 0
    h = "巳"

    for i in range(0, 60):
        S.append("%s%s" % (A[a], B[b]))

        a += 1
        b += 1

        if a == 10:
            a = 0
        if b == 12:
            b = 0
            
    p = random.randint(0, 59)
    l = []
    
    for i in range(0, 9):
        l.append(S[p])
        p += 1
        
        if p == 60:
            p = 0
            
    a = RP[h]
    
    for i in range(0, 9):
        b = R[a]
        
        M[b[0] - 1][b[1] - 1] = l[i]
        
        a += 1
        if a == 9:
            a = 0
    print("""
       -------------------
      | %s | %s | %s |
       -------------------
      | %s | %s | %s |
       -------------------
      | %s | %s | %s |
       -------------------
    """ % (
        M[0][0], M[0][1], M[0][2],
        M[1][0], M[1][1], M[1][2],
        M[2][0], M[2][1], M[2][2],
    ))
