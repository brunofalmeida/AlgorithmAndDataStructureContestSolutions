DEBUG = False

N = int (raw_input ())
T = int (raw_input ())

grid = {}

for i in range (N):
    [x1, y1, x2, y2, t] = map (int, raw_input ().strip ().split () )

    if DEBUG:
        for (x, y) in grid:
            print x, y, ":", grid [(x, y)]

    for x in range (x1, x2):
        for y in range (y1, y2):
            if (x, y) not in grid.keys ():
                grid [(x, y)] = 0
            grid [(x, y)] += t

count = 0
for tint in grid.values ():
    if tint >= T:
        count += 1

print count
