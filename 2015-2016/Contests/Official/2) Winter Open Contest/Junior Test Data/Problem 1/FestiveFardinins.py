import sys
import random
for test in range(1,11):
    sys.stdout = open("FestiveFardin."+str(test)+".in","w")
    if test == 1:
        a = 'green'
        b = 'yellow'
    if test == 2:
        a = 'blue'
        b = 'cyan'
    if test == 3:
        a = 'green'
        b = 'red'
    if test == 4:
        a = 'the colour of grass'
        b = 'the colour of the crisp snow'
    if test == 5:
        a = 'red'
        b = 'white'
    if test == 6:
        a = 'white'
        b = 'green'
    if test == 7:
        a = 'silver'
        b = 'red'
    if test == 8:
        a = 'rouge'
        b = 'red'
    if test == 9:
        a = 'brown'
        b = 'white'
    if test == 10:
        a = 'white'
        b = 'white'
    print a
    print b
    sys.stdout.close()
    
