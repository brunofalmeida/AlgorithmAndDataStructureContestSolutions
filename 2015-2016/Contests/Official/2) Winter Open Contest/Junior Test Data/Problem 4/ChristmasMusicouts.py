import sys
for test in range(1, 11):
    sys.stdin = open("ChristmasMusic." + str(test) + ".in", "r")
    sys.stdout = open("ChristmasMusic." + str(test) + ".out", "w")
    
    trans = {'C':0,'D':1,'E':2,'F':3,'G':4,'A':5,'B':6}

    notes = []

    for i in range(int(raw_input())):
        note = raw_input()
        value = int(note[1])*7+trans[note[0]]
        notes.append(value)

    good = True
    leap = False
    up = None
    prev = notes[0]
    for T in range(1,len(notes)):
        diff = notes[T]-prev
        change = abs(diff)
        if diff > 0:
            direction = True
        elif diff == 0:
            direction = None
        elif diff < 0:
            direction = False
        if change > 7:
            good = False
            break
        if change >= 4 and leap:
            good = False
            break
        if leap and direction == up:
            good = False
            break
        if change >= 4:
            leap = True
        else:
            leap = False
        up = direction
        prev = notes[T]

    if good:
        print "Melodious!"
    else:
        print "Salieri's music"
    sys.stdout.close()
        
