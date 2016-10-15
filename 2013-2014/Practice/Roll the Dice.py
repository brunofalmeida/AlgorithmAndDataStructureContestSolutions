def num_combos (m, n):
    counter = 0
    for x in range (1, m + 1):
        for y in range (1, n + 1):
            if x + y == 10:
                counter += 1

    return counter

m = int (raw_input ())
n = int (raw_input ())
ways = num_combos (m, n)

if ways == 1:
    print "There is 1 way to get the sum 10."
else:
    print "There are", ways, "ways to get the sum 10."
