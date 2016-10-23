N, G = map(int, raw_input().strip().split())
number = 0

for i in range(N):
    Fi = int(raw_input())

    if Fi % G == 0:
        number += 1

print number
