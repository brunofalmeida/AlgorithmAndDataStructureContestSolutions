number_times = input ()

for x in range (number_times):
    bearing = input ()
    if bearing <= 45 or bearing >= 315:
        print "N"
    elif bearing <= 135:
        print "E"
    elif bearing <=225:
        print "S"
    else:
        print "W"
