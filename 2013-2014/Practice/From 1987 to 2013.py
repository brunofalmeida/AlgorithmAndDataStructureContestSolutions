Y = int (raw_input ())
year = Y + 1

while True:
    year_string = str (year)
    digits = []
    is_distinct = True
    for x in year_string:
        if x in digits:
            is_distinct = False
        else:
            digits.append (x)

    if is_distinct:
        print year
        break

    year += 1
