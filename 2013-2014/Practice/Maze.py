DEBUG = False

for t in range (int (raw_input ())):
    r = int (raw_input ())  # height
    c = int (raw_input ())  # width
    
    directions = [[None for y in range (r)] for x in range (c)]
    for y in range (r):
        row = raw_input ().strip ()
        for x in range (c):
            directions [x] [y] = row [x]

    if DEBUG:
        print "Directions:"
        for y in range (r):
            for x in range (c):
                print directions [x] [y],
            print

    grid = {}   # adjacency list
    for x in range (c):
        for y in range (r):
            grid [(x, y)] = []
            if directions [x] [y] == "+":
                if y >= 1 and directions [x] [y - 1] != "*":  # north
                    grid [(x, y)].append ((x, y - 1))
                    
                if y <= r - 2 and directions [x] [y + 1] != "*":  # south
                    grid [(x, y)].append ((x, y + 1))
                    
                if x >= 1 and directions [x - 1] [y] != "*":  # west
                    grid [(x, y)].append ((x - 1, y))
                    
                if x <= c - 2 and directions [x + 1] [y] != "*":  # east
                    grid [(x, y)].append ((x + 1, y))

            elif directions [x] [y] == "-":
                if x >= 1 and directions [x - 1] [y] != "*":  # west
                    grid [(x, y)].append ((x - 1, y))
                    
                if x <= c - 2 and directions [x + 1] [y] != "*":  # east
                    grid [(x, y)].append ((x + 1, y))

            elif directions [x] [y] == "|":
                if y >= 1 and directions [x] [y - 1] != "*":  # north
                    grid [(x, y)].append ((x, y - 1))
                    
                if y <= r - 2 and directions [x] [y + 1] != "*":  # south
                    grid [(x, y)].append ((x, y + 1))

    if DEBUG:
        print "Grid:"
        for point in grid.keys ():
            print point, ": ", grid [point]
                
    queue = [(0, 0)]
    distance = [[-1 for y in range (r)] for x in range (c)]
    distance [0] [0] = 1

    while len (queue) > 0:
        (x, y) = queue.pop (0)

        if (x, y) == (c - 1, r - 1):
            break

        for (x2, y2) in grid [(x, y)]:
            if distance [x2] [y2] == -1 or distance [x] [y] + 1 < distance [x2] [y2]:
                distance [x2] [y2] = distance [x] [y] + 1
                queue.append ((x2, y2))

        if DEBUG:
            print "Queue:", queue
            
            print "Distances:"
            for y in range (r):
                for x in range (c):
                    print distance [x] [y],
                print
            

    print distance [-1] [-1]
