N = int(raw_input())
for i in range(N):
    num = int(raw_input())

    nasty = False
    pairs = []

    for i in range(1, int(num ** 0.5) + 1):
        if num % i == 0:
            pairs.append((i, num / i))

    for i1 in range(0, len(pairs) - 1):
        for i2 in range(1, len(pairs)):
            if i1 != i2:
                pair1 = pairs[i1]
                pair2 = pairs[i2]

                if ( abs(pair1[0] - pair1[1]) ) == ( pair2[0] + pair2[1] ):
                    nasty = True

    if nasty:
        print num, "is nasty"
    else:
        print num, "is not nasty"
