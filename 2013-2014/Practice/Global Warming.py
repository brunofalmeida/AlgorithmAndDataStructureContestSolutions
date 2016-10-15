while True:
    inp = map (int, raw_input ().strip ().split ())
    if inp [0] == 0:
        break
    temps = inp [1:]
    tempchanges = []
    for i in range (1, len (temps)):
        tempchanges.append (temps [i] - temps [i - 1])

    cycles = []
    for i in range (1, len (tempchanges)):
        cycles.append (list (tempchanges [0: i]))

    for i, cycle in enumerate (cycles):
        repeat = tempchanges [len (cycle):]
        while len (repeat) > len (cycle):
            del repeat [-1]

        if repeat == cycle [:len (repeat)]:
            print len (cycle)
            break

    else:
        print len (tempchanges)
