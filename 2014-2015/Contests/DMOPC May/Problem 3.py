N = int(raw_input())    # number of mollusks
A, B = map(int, raw_input().strip().split())    # right, left

right = map(int, raw_input().strip().split())
left = map(int, raw_input().strip().split())

shells = [ [False, False] for i in range(10**6) ]
for n in right:
    shells[n][0] = True
for n in left:
    shells[n][1] = True

complete = 0
for i in range(1, 10**6):
    if shells[i][0] and shells[i][1]:
        complete += 1
print N - complete
