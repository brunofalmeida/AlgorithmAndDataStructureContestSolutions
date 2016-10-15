cents = input ()
cents_left = cents
quarters_string = ""
dimes_string = ""
nickels_string = ""
pennies_string = ""

if cents_left >= 25:
    quarters = cents_left / 25
    cents_left = cents_left % 25
    if quarters > 0:
        if quarters == 1:
            quarters_string = " 1 quarter"
        else:
            quarters_string = " " + str (quarters) + " quarters"
        if cents_left > 0:
            quarters_string = quarters_string + ","
        else:
            quarters_string = quarters_string + "."

if cents_left >= 10:
    dimes = cents_left / 10
    cents_left = cents_left % 10
    if dimes > 0:
        if dimes == 1:
            dimes_string = " 1 dime"
        else:
            dimes_string = " " + str (dimes) + " dimes"
        if cents_left > 0:
            dimes_string = dimes_string + ","
        else:
            dimes_string = dimes_string + "."

if cents_left >= 5 :
    nickels = cents_left / 5
    cents_left = cents_left % 5
    if nickels > 0:
        if nickels == 1:
            nickels_string = " 1 nickel"
        else:
            nickels_string = " " + str (nickels) + " nickels"
        if cents_left > 0:
            nickels_string = nickels_string + ","
        else:
            nickels_string = nickels_string + "."

if cents_left > 0:
    pennies = cents_left
    if pennies > 0:
        if pennies == 1:
            pennies_string = " 1 cent"
        else:
            pennies_string = " " + str (pennies) + " cents"
        if cents_left > 0:
            pennies_string = pennies_string + "."

print str (cents), "cents requires" + quarters_string + dimes_string + nickels_string + pennies_string
