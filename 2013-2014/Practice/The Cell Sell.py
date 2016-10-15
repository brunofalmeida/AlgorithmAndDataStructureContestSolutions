def a (daytime, evening, weekend):
    total = 0
    if daytime > 100:
        total += 0.25 * (daytime - 100)
    total += 0.15 * evening
    total += 0.20 * weekend

    return total

def b (daytime, evening, weekend):
    total = 0
    if daytime > 250:
        total += 0.45 * (daytime - 250)
    total += 0.35 * evening
    total += 0.25 * weekend

    return total

daytime = int (raw_input ())
evening = int (raw_input ())
weekend = int (raw_input ())

A = a (daytime, evening, weekend)
B = b (daytime, evening, weekend)

print "Plan A costs", A
print "Plan B costs", B

if A == B:
    print "Plan A and B are the same price."
elif A < B:
    print "Plan A is cheapest."
elif B < A:
    print "Plan B is cheapest."
