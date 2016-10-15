N = int(raw_input())
beads = raw_input()

groups = 1
for i in range(1, N):
    if beads[i] != beads[i - 1]:
        groups += 1

if groups != 3:
    print "FIX YOUR BEADS!"
else:
    print "Organized"
