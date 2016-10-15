t = int (raw_input ())
s = int (raw_input ())
h = int (raw_input ())

for x in range (t):
    print ("*" + (" " * s)) * 2 + "*"
    print

print "*" * (2 * s + 3)

for x in range (h):
    print
    print " " * (s + 1) + "*"
