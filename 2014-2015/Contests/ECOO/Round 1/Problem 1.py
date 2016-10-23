import sys
sys.stdin = open("DATA11.txt","r")

for q in xrange(10):

    colours = [ 0 for w in xrange(8)]
    
    line = raw_input().strip()

    while line != "end of box":

        if line == "orange":
            colours[0] += 1
        elif line == "blue":
            colours[1] += 1
        elif line == "green":
            colours[2] += 1
        elif line == "yellow":
            colours[3] += 1
        elif line == "pink":
            colours[4] += 1
        elif line == "violet":
            colours[5] += 1
        elif line == "brown":
            colours[6] += 1
        elif line == "red":
            colours[7] += 1

        line = raw_input().strip()

    time = 0

    for qw in xrange(len(colours)):
        if qw != 7:
            time += ((colours[qw] / 7)*13)
            if colours[qw] % 7 != 0:
                time += 13
        else:
            time += colours[qw] * 16
    print time
        
