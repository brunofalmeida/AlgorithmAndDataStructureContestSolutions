N, M = map(int, raw_input().strip().split())

henchmen = []
for i in range(N):
    henchmen.append(int(raw_input()))

doors = []
for i in range(M):
    doors.append(int(raw_input()))


doors_closed = [True for i in range(M)]

doors_sorted = doors[:]
doors_sorted.sort()

doors_sorted_indices = [0 for i in range(M)]
for i, door in enumerate(doors_sorted):
    doors_sorted_indices[i] = doors.index(door)

min_index = 0
min_door = doors[doors_sorted_indices[min_index]]

for i in range(0, M):
    door = doors[i]
    doors_closed[i] = False

    if i == M - 1:
        print N
    else:
        if door == min_door:
            min_index += 1
            while not doors_closed[doors_sorted_indices[min_index]]:
                min_index += 1

            min_door = doors[doors_sorted_indices[min_index]]

        count = 0
        for henchman in henchmen:
            if henchman < min_door:
                count += 1
        print count
