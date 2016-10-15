def is_leap (year):
    if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):
        return True
    else:
        return False

counter = input ()

for x in range (counter):
    [Y, M, D] = raw_input ().strip ().split ()
    Y = int (Y)
    M = int (M)
    D = int (D)

    # Months
    if M == 1:
        days = 0
    if M == 2:
        days = 31
    elif M == 3:
        days = 59
    elif M == 4:
        days = 90
    elif M == 5:
        days = 120
    elif M == 6:
        days = 151
    elif M == 7:
        days = 181
    elif M == 8:
        days = 212
    elif M == 9:
        days = 243
    elif M == 10:
        days = 273
    elif M == 11:
        days = 304
    elif M == 12:
        days = 334

    # Days
    days += D

    # Leap Year
    if is_leap (Y) and M > 2:
        days += 1

    print days
