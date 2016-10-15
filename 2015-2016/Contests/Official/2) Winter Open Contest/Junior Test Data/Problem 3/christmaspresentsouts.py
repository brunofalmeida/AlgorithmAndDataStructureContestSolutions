import sys
for test in range(1,11):
    sys.stdin = open("ChristmasPresents."+str(test)+".in","r")
    sys.stdout = open("ChristmasPresents."+str(test)+".out","w")
    presents = int(raw_input())
    teachers = int(raw_input())

    ps = []
    ts = []
    for i in range(presents):
        a = raw_input()
        b = float(raw_input())
        ps.append([b,a])

    for i in range(teachers):
        a = raw_input()
        b = float(raw_input())
        ts.append([b,a])

    ps.sort()
    ts.sort()

    for i in range(len(ts)):
        print ts[i][1],'will get a',ps[i][1]

    sys.stdout.close()
