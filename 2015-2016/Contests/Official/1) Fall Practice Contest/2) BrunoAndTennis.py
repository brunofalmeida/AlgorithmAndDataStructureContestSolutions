N = int(raw_input())

bad = False
lob = False

for i in range(N / 2):
    first = raw_input()
    second = raw_input()
    
    if first == "lob" and second != "lob":
        bad = True
    if first != "lob" and second == "lob":
        bad = True
    if first == "lob" or second == "lob":
        lob = True

if lob:
    if bad:
        print "BruNO"
    else:
        print "Possible Bruno"
else:
    print "Not enough information"
