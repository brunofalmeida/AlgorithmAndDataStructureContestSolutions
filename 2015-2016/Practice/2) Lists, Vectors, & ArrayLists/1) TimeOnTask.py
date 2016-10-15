# http://wcipeg.com/problem/ccc13j4


T = int(raw_input())
C = int(raw_input())

chores = [0 for i in range(C)]
for i in range(C):
    chores[i] = int(raw_input())


chores.sort()

minutes = 0
counter = 0

for time in chores:
    if (minutes + time) <= T:
        minutes += time
        counter += 1

print counter
