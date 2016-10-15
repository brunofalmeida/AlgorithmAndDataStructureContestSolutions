counter = int (raw_input ())

for x in range (counter):
    grams = int (raw_input ())

    if grams <= 30:
        cents = 38
    elif grams <= 50:
        cents = 55
    elif grams <= 100:
        cents = 73
    else:
        cents = 73
        extra_units = (grams - 100) / 50.0
        if extra_units % 1 == 0:
            cents += int (extra_units) * 24
        else:
            cents += (int (extra_units) + 1) * 24

    print cents
