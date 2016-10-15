question = int(raw_input())
N = int(raw_input())
dmoj = map(int, raw_input().strip().split())
peg = map(int, raw_input().strip().split())

dmoj.sort()
peg.sort()

pairs = []

if question == 1:
    for i in range(N):
        a = dmoj.pop(-1)
        b = peg.pop(-1)
        pairs.append((a, b))

elif question == 2:
    for num in range(N):
        a = dmoj[-1]
        b = peg[-1]

        if a > b:
            dmoj.pop(-1)
            b = peg.pop(0)
        else:
            peg.pop(-1)
            a = dmoj.pop(0)

        pairs.append((a, b))


sum = 0
for pair in pairs:
    sum += max(pair[0], pair[1])
print sum
