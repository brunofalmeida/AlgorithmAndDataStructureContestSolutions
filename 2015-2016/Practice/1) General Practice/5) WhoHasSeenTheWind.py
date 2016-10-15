# http://wcipeg.com/problem/ccc11j2


h = int(raw_input())
M = int(raw_input())

hour = 0

for t in range (1, M + 1):
    altitude = -(6 * t**4) + (h * t**3) + (2 * t**2) + (t)
    if altitude <= 0:
        hour = t
        break

if hour == 0:
    print "The balloon does not touch ground in the given time."
else:
    print "The balloon first touches ground at hour:"
    print hour
