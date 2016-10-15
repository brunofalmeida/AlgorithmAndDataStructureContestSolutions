import sys
import random
for test in range(1, 21):
    sys.stdout = open("Trig." + str(test) + ".in", "w")
    if test == 1:
        a = 1
        b = 1
        c = 1
    if test == 2:
        a = 1
        b = 2
        c = 1
    if test == 3:
        a = 2
        b = 4
        c = 2
    if test == 4:
        a = 15
        b = 4
        c = 12
    if test == 5:
        a = 8
        b = 17
        c = 8
    if test == 6:
        a = 6
        b = 4
        c = 3
    if test > 6 and test <= 8:
        a = random.randint(1, 100)
        b = random.randint(1, 100)
        c = random.randint(1, 100)
        while (a + b > c and b + c > a and c + a > b):
            a = random.randint(1, 100)
            b = random.randint(1, 100)
            c = random.randint(1, 100)
    if test > 8 and test <= 10:
        a = random.randint(1, 100)
        b = random.randint(1, 100)
        c = random.randint(1, 100)
        while (a + b <= c or b + c <= a or c + a <= b):
            a = random.randint(1, 100)
            b = random.randint(1, 100)
            c = random.randint(1, 100)
    if test > 10:
        if test % 2 == 0:
            a = random.randint(1, 1000)
            b = random.randint(1, 1000)
            c = random.randint(1, 1000)
            while (a + b <= c or b + c <= a or c + a <= b):
                a = random.randint(1, 1000)
                b = random.randint(1, 1000)
                c = random.randint(1, 1000)
        else:
            a = random.randint(1, 1000)
            b = random.randint(1, 1000)
            c = random.randint(1, 1000)
            while (a + b > c and b + c > a and c + a > b):
                a = random.randint(1, 1000)
                b = random.randint(1, 1000)
                c = random.randint(1, 1000)
    print a
    print b
    print c
    sys.stdout.close()
