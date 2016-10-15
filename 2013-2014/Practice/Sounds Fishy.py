readings = []
for x in range (4):
    readings.append (input ())

if readings [0] == readings [1] == readings [2] == readings [3]:
    print "Fish At Constant Depth"
    
elif readings [0] < readings [1] < readings [2] < readings [3]:
    print "Fish Rising"

elif readings [0] > readings [1] > readings [2] > readings [3]:
    print "Fish Diving"

else:
    print "No Fish"
