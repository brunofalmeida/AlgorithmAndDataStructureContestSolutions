X = int (raw_input ())
Y = int (raw_input ())

for x in range (X, Y + 1):
    if x % 60.0 == X % 60:
        print "All positions change in year", x
