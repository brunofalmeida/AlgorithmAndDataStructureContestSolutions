import sys
for test in range(1,11):
    sys.stdin = open("FestiveFardin."+str(test)+".in","r")
    sys.stdout = open("FestiveFardin."+str(test)+".out","w")

    shirt = raw_input()
    pants = raw_input()

    if shirt == 'green' or shirt == 'red' or shirt == 'white':
        if pants == 'green' or pants == 'red' or pants == 'white':
            print "Jingle Bells"
        else:
            print "boring..."
    else:
        print "boring..."
    sys.stdout.close()
