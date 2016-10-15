fibonacci = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610]

N = int(raw_input())
S = raw_input()

good = True
numA = 0
for num in fibonacci:
    if num - 1 < len(S):
        if S[num - 1] == "A":
            numA += 1
        else:
            good = False
            break
    else:
        break

if S.count("A") - numA > 0:
    good = False

if good:
    print "That's quite the observation!"
else:
    print "Bruno, GO TO SLEEP"
