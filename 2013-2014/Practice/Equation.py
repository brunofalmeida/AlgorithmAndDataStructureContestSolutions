a = input ()
b = input ()

if a == 0:
    if b == 0:
        print "indeterminate"
    else:
        print "undefined"

else:
    print format (round (0 - (float (b) / a), 2), ".2f")
