import sys
for test in range(1, 21):
    sys.stdin = open("Trig." + str(test) + ".in", "r")
    sys.stdout = open("Trig." + str(test) + ".out", "w")

    a = int(raw_input())
    b = int(raw_input())
    c = int(raw_input())

    if a + b > c and b + c > a and a + c > b:
        print "Huh? A triangle?"
    else:
        print "Maybe I should go out to sea..."
    sys.stdout.close()
