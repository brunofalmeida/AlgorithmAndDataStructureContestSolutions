from math import *

for i in range (10):
    [rA, rB, vA, vB, a, b, t] = map (float, raw_input ().strip ().split () )

    a = radians (a)
    b = radians (b)

    xA = (rA * cos(a)) + (cos(a) * vA * t)
    yA = (rA * sin(a)) + (sin(a) * vA * t)

    xB = (rB * cos(b)) + (cos(b) * vB * t)
    yB = (rB * sin(b)) + (sin(b) * vB * t)

    print format (round ( ( (xA - xB) ** 2 + (yA - yB) ** 2) ** 0.5, 2), ".2f")
