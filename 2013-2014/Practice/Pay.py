T = int (raw_input ())
for i in range (T):
    hourly_rate = float (raw_input ())
    hours = int (raw_input ())
    category = raw_input ()
    is_donating = raw_input ()

    pay = hours * hourly_rate
    if hours > 40:
        pay += (hours - 40) * hourly_rate

    if category == "B":
        pay *= 0.9
    elif category == "C":
        pay *= 0.8
    elif category == "D":
        pay *= 0.71
    elif category == "E":
        pay *= 0.65

    if is_donating == "y":
        pay -= 10

    print format (round (pay, 2), ".2f")

    raw_input ()
