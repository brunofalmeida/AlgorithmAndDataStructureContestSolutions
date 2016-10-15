while True:
    account = raw_input ()
    if int (account) < 0:
        break
    readings = raw_input ().strip ().split ()
    readings [0] = int (readings [0])
    readings [1] = int (readings [1])

    difference = readings [1] - readings [0]
    while difference < 0:
        difference += 10000

    charge = 6.59
    remaining = difference - 10
    
    if remaining > 0:
        if remaining >= 20:
            charge += 0.2373 * 20
        else:
            charge += 0.2373 * remaining
        remaining -= 20

    if remaining > 0:
        if remaining >= 55:
            charge += 0.2271 * 55
        else:
            charge += 0.2271 * remaining
        remaining -= 55

    if remaining > 0:
        if remaining >= 85:
            charge += 0.2178 * 85
        else:
            charge += 0.2178 * remaining
        remaining -= 85

    if remaining > 0:
        charge += 0.2085 * remaining

    print "Account #:", account
    print "Bill:", format (round (charge, 2), ".2f")
