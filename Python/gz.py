from api import day

YEAR = 2020
FILE = open("g", "w")

if __name__ == "__main__":
    while YEAR < 2100:
        FILE.write("\"%d\"\n" % YEAR)
        for i in range(1, 13):
            w = day(YEAR, i, 1)[1]

            FILE.write(
                "\"%s %s %s\\n\"\n"
                % (
                    w[0],
                    w[1],
                    w[2],
                )
            )

        YEAR += 1
