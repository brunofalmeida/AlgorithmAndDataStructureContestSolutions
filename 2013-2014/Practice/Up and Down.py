a = int (raw_input ())
b = int (raw_input ())
c = int (raw_input ())
d = int (raw_input ())
s = int (raw_input ())

nikky = s / (a + b) * (a - b)
byron = s / (c + d) * (c - d)


for x in range ((a + b) * (s / (a + b)) + 1, s + 1):
    if x % (a + b) <= a and x % (a + b) != 0:
        nikky += 1
    else:
        nikky -= 1

for x in range ((c + d) * (s / (c + d)) + 1, s + 1):
    if x % (c + d) <= c and x % (c + d) != 0:
        byron += 1
    else:
        byron -= 1

if nikky > byron:
    print "Nikky"
elif byron > nikky:
    print "Byron"
else:
    print "Tied"
