N = int(raw_input())
difficulties = map(int, raw_input().strip().split())

problems = []
for d in difficulties:
    if d not in problems:
        problems.append(d)

print len(problems)
