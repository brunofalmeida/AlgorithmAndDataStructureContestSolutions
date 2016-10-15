# converts scientific notation to a normal number
def number(coeff, exp):
    return coeff * 10 ** exp

# short form for degrees to radians conversion (radians() from math library)
def rad(rads):
    return radians(rads)

# given a starting point (X, Y), triangle hypotenuse length, and angle rotation (in standard trig position),
# calculates a new point
def point(X, Y, length, ang):
    # cos() and sin() from math library - take radians as input
    return ( X + length * cos(rad(ang)), Y + length * sin(rad(ang)) )


# file input
import sys
sys.stdin = open("DATA31.txt", "r")

# import math library for radians conversion and trig functions
from math import *

# 10 test cases
for test in range(10):

    # input 7 numbers on line
    line = raw_input().strip().split()

    # convert and assign X, Y, and S, assign N
    X = float( number( float(line[0]), int(line[1]) ) ) # X of head pin
    Y = float( number( float(line[2]), int(line[3]) ) ) # Y of head pine
    S = float( number( float(line[4]), int(line[5]) ) ) # side length
    N = int(line[6])                                    # precision (number of decimal places)

    # list of coordinates for which to find nearest pin
    positions = []

    # input 5 coordinates
    for i in range(5):
        
        # input line
        line = raw_input().strip().split()

        # convert and assign x and y coordinates
        xPos = float( number( float(line[0]), int(line[1]) ) )
        yPos = float( number( float(line[2]), int(line[3]) ) )

        # add point to positions
        positions.append((xPos, yPos))

    # each item represents the coordinates of the pin at that index
    pins = [None for i in range(11)]

    # calculate coordinates of each pin

    # head pin
    pins[1] = (X, Y)

    # pins on left side (120 degree rotation in standard position)
    # equilateral triangle - each angle 60 degrees
    # in standard position, rotation 90 degrees plus 30 degrees (half of angle) = 120 degrees
    pins[2] = point(X, Y, S / 3.0, 120)
    pins[4] = point(X, Y, S * 2 / 3.0, 120)
    pins[7] = point(X, Y, S, 120)

    # pins on right side (60 degree rotation in standard position)
    # equilateral triangle - each angle 60 degrees
    # in standard position, rotation 90 degrees minus 30 degrees (half of angle) = 60 degrees
    pins[3] = point(X, Y, S / 3.0, 60)
    pins[6] = point(X, Y, S * 2 / 3.0, 60)
    pins[10] = point(X, Y, S, 60)

    # centre pin (same X as head pin, same Y as pin 4 or 6)
    pins[5] = ( pins[1][0], pins[4][1] )

    # pins on top side (X = 1/3 of side length from pins 7 and 10, same Y)
    pins[8] = ( pins[7][0] + S / 3.0, pins[7][1] )
    pins[9] = ( pins[10][0] - S / 3.0, pins[10][1] )

    # for each position
    for position in positions:

        # find pin closest to position
        closestPin = -1
        minDistance = 999999999

        # for each pin
        for i in range(1, 11):

            # calculate distance from position to pin (Pythagorean theorem)
            distance = ( (position[0] - pins[i][0]) ** 2 + (position[1] - pins[i][1]) ** 2 ) ** 0.5

            # if distance is less than minDistance, set that pin as closest with that distance
            if distance < minDistance:
                closestPin = i
                minDistance = distance

        # print closest pin, keeping next print on same line
        print closestPin,

    # done printing pins for this test case, so move print to new line for next test case
    print
