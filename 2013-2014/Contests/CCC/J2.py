V = int (raw_input ())
inp = raw_input ()

votes = {"A":0, "B":0}
for p in inp:
    votes [p] += 1

if votes ["A"] > votes ["B"]:
    print "A"
elif votes ["B"] > votes ["A"]:
    print "B"
else:
    print "Tie"
