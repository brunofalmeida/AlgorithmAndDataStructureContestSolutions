while True:
    C = int (raw_input ())
    if C == 0:
        break

    sqrt = int (C ** 0.5)
    for x in range (sqrt + 1, 1, -1):
        if C % x == 0:
            y = C / x
            break

    if x <= y:
        print "Minimum perimeter is", (x + y) * 2, "with dimensions", x, "x", y
    else:
        print "Minimum perimeter is", (x + y) * 2, "with dimensions", y, "x", x
