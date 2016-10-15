N = int(raw_input())
meditation = map(int, raw_input().strip().split())
M = int(raw_input())
count = 0
for i in range(M):
    a, d = map(int, raw_input().strip().split())

    if meditation[a - 1] < meditation[a]:
        if meditation[a - 1] < d:
            meditation[a - 1] = 0
        else:
            count += d
    else:
        if meditation[a] < d:
            meditation[a] = 0
        else:
            count += d

print sum(meditation)-count
