N = int(raw_input())
seq = raw_input()

f = [1, 1]

while f[-1] < N:
    f.append(f[-2] + f[-1])

count = 0
bad = False

for i in f[1:]:
    if i <= N:
        if seq[i - 1] == 'A':
            count += 1
        else:
            bad = True

if bad or count != seq.count('A'):
    print "Bruno, GO TO SLEEP"
else:
    print "That's quite the observation!"
