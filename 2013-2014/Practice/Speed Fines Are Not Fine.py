limit = input ()
speed = input ()
difference = speed - limit

if difference <= 0:
    print "Congratulations, you are within the speed limit!"
else:
    if difference >= 31:
        fine = 500
    elif difference >= 21:
        fine = 270
    else:
        fine = 100
    print "You are speeding and your fine is $" + str (fine) + "."
