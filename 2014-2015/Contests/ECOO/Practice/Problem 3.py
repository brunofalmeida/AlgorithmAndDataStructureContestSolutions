import sys
sys.stdin = open("DATA31.txt", "r")

from math import *


def rad(deg):
    return radians(deg)

def deg(rad):
    return degrees(rad)

# format
def f(deg):
    return deg % 360

def point(ang, length):
    return [length * cos(rad(ang)),
            length * sin(rad(ang))]

for test in range(5):
    Px, Py = map(float, raw_input().strip().split())
    length = sqrt(Px ** 2 + Py ** 2)
    height = 2 * sqrt(length ** 2 - (length / 2) ** 2)

    angP = f(deg(asin(abs(Py / length))))
    if Py > 0:
        if Px < 0:
            angP = 180 - angP
    if Py < 0:
        if Px < 0:
            angP = 180 + angP
        if Px > 0:
            angP = 360 - angP
    angP = f(angP)

    angP1 = f(angP - 30)
    angP2 = f(angP1 - 90)
    angP3 = f(angP1 + 90)

    p1 = point(angP1, height)
    p2 = point(angP2, length)
    p3 = point(angP3, length)
    print "("+str(format(round(p1[1], 1), ".1f")) + "," +str(format(round(p1[0], 1), ".1f")) +")",
    print "("+str(format(round(p2[1], 1), ".1f")) + "," +str(format(round(p2[0], 1), ".1f")) +")",
    print "("+str(format(round(p3[1], 1), ".1f")) + "," +str(format(round(p3[0], 1), ".1f")) +")"
