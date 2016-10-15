N = int(raw_input())
s = list(raw_input())

s2 = s[:]
s2.sort()

for i in range(N):
    if s[i] != s2[i]:
        print "FIX YOUR BEADS!"
        break

else:
    print "Organized"
