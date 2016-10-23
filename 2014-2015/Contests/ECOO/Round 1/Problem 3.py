def number(coeff, exp):
    return coeff * 10 ** exp

def rad(rads):
    return radians(rads)

def point(X, Y, length, ang):
    return ( X + length * cos(rad(ang)), Y + length * sin(rad(ang)) )


import sys
sys.stdin = open("DATA31.txt", "r")

from math import *


######################################
for test in range(10):
    line = raw_input().strip().split()

    X = float( number( float(line[0]), int(line[1]) ) ) # head pin
    Y = float( number( float(line[2]), int(line[3]) ) )
    S = float( number( float(line[4]), int(line[5]) ) ) # side length
    N = int(line[6])    # precision (number of decimals)

    positions = []
    ######################################
    for i in range(5):
        line = raw_input().strip().split()

        xPos = float( number( float(line[0]), int(line[1]) ) )
        yPos = float( number( float(line[2]), int(line[3]) ) )

        positions.append((xPos, yPos))

    pins = [None for i in range(11)]

    pins[1] = (X, Y)
    
    pins[2] = point(X, Y, S / 3.0, 120)
    pins[4] = point(X, Y, S * 2 / 3.0, 120)
    pins[7] = point(X, Y, S, 120)

    pins[3] = point(X, Y, S / 3.0, 60)
    pins[6] = point(X, Y, S * 2 / 3.0, 60)
    pins[10] = point(X, Y, S, 60)

    pins[5] = ( pins[1][0], pins[4][1] )

    pins[8] = ( pins[7][0] + S / 3.0, pins[7][1] )
    pins[9] = ( pins[10][0] - S / 3.0, pins[10][1] )

    for position in positions:
        closestPin = -1
        minDistance = 999999999
        
        for i in range(1, 11):
            distance = ( (position[0] - pins[i][0]) ** 2 + (position[1] - pins[i][1]) ** 2 ) ** 0.5
            if distance < minDistance:
                closestPin = i
                minDistance = distance
        print closestPin,
    print
