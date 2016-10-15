N = int (raw_input ())
T = int (raw_input ())

K = 1000         # change based on test case
grid = [ [0 for i in xrange (K + 1) ] for j in xrange (K + 1) ]

for i in range (N):
    inp = map (int, raw_input ().strip ().split () )

    for x in range (inp [0], inp [2]):
        for y in range (inp [1], inp [3]):
            grid [x] [y] += inp [4]

count = 0
for column in grid:
    for point in column:
        if point >= T:
            count += 1

print count
