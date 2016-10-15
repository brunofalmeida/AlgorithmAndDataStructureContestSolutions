trout_p = int (raw_input ())
pike_p = int (raw_input ())
pickerel_p = int (raw_input ())
total = int (raw_input ())

trout_m = total / trout_p
pike_m = total / pike_p
pickerel_m = total / pickerel_p

def points (trout, pike, pickerel):
    global trout_p
    global pike_p
    global pickerel_p
    return trout * trout_p + pike * pike_p + pickerel * pickerel_p

counter = 0
for trout in range (trout_m + 1):
    for pike in range (pike_m + 1):
        for pickerel in range (pickerel_m + 1):
            if points (trout, pike, pickerel) <= total and (not trout == pike == pickerel == 0):
                print trout, "Brown Trout,", pike, "Northern Pike,", pickerel, "Yellow Pickerel"
                counter += 1

print "Number of ways to catch fish:", counter
