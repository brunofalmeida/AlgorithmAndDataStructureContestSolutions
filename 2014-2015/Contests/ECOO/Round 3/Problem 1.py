import sys
sys.stdin = open("DATA11.txt", "r")

for test in range(10):
    digitList = list(raw_input().strip())

    output = ["0" for i in range(int(digitList[-1]))]

    placeIndex = int(digitList[-1])
    while len(digitList) > 0:
        digits = digitList[-1]
        digitList = digitList[:-1]

        while len(digitList) > 0 and int(digitList[-1] + digits) <= placeIndex:
            digits = digitList[-1] + digits
            digitList = digitList[:-1]
        output = [digits] + output

        if len(digitList) > 0:
            output = ["0" for i in range(int(digitList[-1]) - len(output))] + output

        placeIndex = len(output)

    for digits in output:
        print digits,
    print
