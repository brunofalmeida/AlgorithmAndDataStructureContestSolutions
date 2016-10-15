a, b = raw_input().strip().split()

if len(a) == 3 and len(b) == 7 and a in ["416", "647", "437"]:
    if a == "416":
        print "valuable"
    else:
        print "valueless"
else:
    print "invalid"
