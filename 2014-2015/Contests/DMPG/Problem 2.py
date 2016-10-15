R, N = map(int, raw_input().strip().split())

regions = []
for i in range(R):
    regions.append(map(int, raw_input().strip().split()))

count = 0
flag = [False for i in range(R)]
for i in range(N):
    x, y = map(int, raw_input().strip().split())

    for index, region in enumerate(regions):
        if not flag[index]:
            if region[0] <= x < region[0] + region[2]:
                if region[1] <= y < region[1] + region[3]:
                    count += 1
                    flag[index] = True

print count
