J = int (raw_input ())

counter = 0
for x in range (1, J - 2):
    for y in range (2, J - 1):
        for z in range (3, J):
            players = [x, y, z]
            if players [0] < players [1] < players [2] < J:
                counter += 1

print counter
