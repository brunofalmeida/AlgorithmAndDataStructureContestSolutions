DEBUG = True

from copy import deepcopy

def update_best (grid):
    global best
    for row in grid:
        best = max (best, max (row) )

def print_grid (grid):
    for row in grid:
        for block in row:
            print block,
        print
    print

for z in range (5):
    grid = []
    for i in range (4):
        grid.append (map (int, raw_input ().strip ().split () ) )

    queue = [grid]
    flag = set ()
    best = 0
    update_best (grid)

    while len (queue) > 0:
        grid = queue.pop (0)

        if DEBUG:
            print "Queue:", queue
            print "Best:", best
            print "Grid:", grid

        # Up
        temp = deepcopy (grid)
        if DEBUG:
            print "Up:"
            print_grid (temp)
        for y in range (1, 4):
            for x in range (0, 4):
                repeat = True
                while repeat:
                    repeat = False
                    if temp [y - 1] [x] == temp [y] [x] and temp [y] [x] != 0:
                        temp [y - 1] [x] *= 2
                        temp [y] [x] = 0
                        repeat = True
                        if DEBUG:
                            print "Merging", y, x, "and", y - 1, x
                    elif temp [y - 1] [x] == 0 and temp [y] [x] != 0:
                        temp [y - 1] [x] == temp [y] [x]
                        temp [y] [x] = 0
                        repeat = True
                        if DEBUG:
                            print "Moving", y, x, "to", y-1, x
                    if DEBUG:
                        print_grid (temp)

        if temp != grid:
            queue.append (temp)
            update_best (temp)


        # Down
        temp = deepcopy (grid)
        if DEBUG:
            print "Down:"
            print_grid (temp)
        for y in range (2, -1, -1):
            for x in range (0, 4):
                repeat = True
                while repeat:
                    repeat = False
                    if temp [y + 1] [x] == temp [y] [x] and temp [y] [x] != 0:
                        temp [y + 1] [x] *= 2
                        temp [y] [x] = 0
                        repeat = True
                        if DEBUG:
                            print "Merging", y, x, "and", y + 1, x
                    elif temp [y + 1] [x] == 0 and temp [y] [x] != 0:
                        temp [y + 1] [x] == deepcopy (temp [y] [x])
                        temp [y] [x] = 0
                        repeat = True
                        if DEBUG:
                            print "Moving", y, x, "to", y + 1, x
                    if DEBUG:
                        print_grid (temp)

        if temp != grid:
            queue.append (temp)
            update_best (temp)

        # Right
        temp = deepcopy (grid)
        if DEBUG:
            print "Right:"
            print_grid (temp)
        for y in range (0, 4):
            for x in range (2, -1, -1):
                repeat = True
                while repeat:
                    repeat = False
                    if temp [y] [x + 1] == temp [y] [x] and temp [y] [x] != 0:
                        temp [y] [x + 1] *= 2
                        temp [y] [x] = 0
                        repeat = True
                        if DEBUG:
                            print "Merging", y, x, "and", y, x + 1
                    elif temp [y] [x + 1] == 0 and temp [y] [x] != 0:
                        temp [y] [x + 1] == temp [y] [x]
                        temp [y] [x] = 0
                        repeat = True
                        if DEBUG:
                            print "Moving", y, x, "to", y, x + 1
                    if DEBUG:
                        print_grid (temp)

        if temp != grid:
            queue.append (temp)
            update_best (temp)

        # Left
        temp = deepcopy (grid)
        if DEBUG:
            print "Left:"
            print_grid (temp)
        for y in range (0, 4):
            for x in range (1, 4):
                repeat = True
                while repeat:
                    repeat = False
                    if temp [y] [x - 1] == temp [y] [x] and temp [y] [x] != 0:
                        temp [y] [x - 1] *= 2
                        temp [y] [x] = 0
                        repeat = True
                        if DEBUG:
                            print "Merging", y, x, "and", y, x - 1
                    elif temp [y] [x - 1] == 0 and temp [y] [x] != 0:
                        temp [y] [x - 1] == temp [y] [x]
                        temp [y] [x] = 0
                        repeat = True
                        if DEBUG:
                            print "Moving", y, x, "to", y, x - 1
                    if DEBUG:
                        print_grid (temp)

        if temp != grid:
            queue.append (temp)
            update_best (temp)


    print best
