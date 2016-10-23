# file input
import sys
sys.stdin = open("DATA11.txt","r")

# 10 test cases
for q in xrange(10):

    # number of candies of each color
    colours = [0 for w in xrange(8)]

    # input colour
    line = raw_input().strip()

    # check for end of input
    while line != "end of box":

        # add 1 candy to that colour
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

        # input colour
        line = raw_input().strip()

    # total time taken
    time = 0

    # go through each colour
    for qw in xrange(len(colours)):

        # if colour is not red
        if qw != 7:
            
            # add 13 seconds for each group of 7 candies
            time += ((colours[qw] / 7)*13)

            # previous calculation rounds down, so add 13 seconds if a partial group was not counted
            if colours[qw] % 7 != 0:
                time += 13

        # if colour is red, add 16 seconds
        else:
            time += colours[qw] * 16

    # output time
    print time
        
