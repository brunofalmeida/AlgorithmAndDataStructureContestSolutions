A = int (raw_input ())
B = int (raw_input ())
R = int (raw_input ())

if A > R:
    print "Bob overdoses on day 1."
elif A * 0.5 + B > R:
    print "Bob overdoses on day 2."
else:
    print "Bob never overdoses."
