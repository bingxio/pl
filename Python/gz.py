from api import get_wnl

YEAR = 2020
FILE = open("gz.txt", "w")

if __name__ == "__main__":
    while YEAR < 2100:
        for i in range(1, 13):
            w = get_wnl(YEAR, i, 1)

            FILE.write(
                '[%d, "%s", "%s", "%s"],\n'
                % (
                    YEAR,
                    w[0],
                    w[1],
                    w[2],
                )
            )

        YEAR += 1
