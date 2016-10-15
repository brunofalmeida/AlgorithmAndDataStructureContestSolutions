def dist (x1, y1, x2, y2):
    return ( (x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5

N = int (raw_input ())

graph = [ [None for i in xrange (-10000, 10001) ] for j in xrange (-10000, 10001) ]
for i in range (N):
    [x, y] = map (int, raw_input ().strip ().split () )
    graph [x] [y] = True


stack = [ (0, 0, 14150, 0) ]
max_treats = 0
while len (stack) > 0:        
    x1, y1, distance, treats = stack.pop ()
    if treats > max_treats:
        max_treats = treats

    for x2 in range (int (x1 - distance) + 1, int (x1 + distance) + 1):
        for y2 in range (int (y1 - distance) + 1, int (y1 + distance) + 1):
            if (x2, y2) != (x1, y1) and graph [x2] [y2] and dist (x1, y1, x2, y2) < distance:
                stack.append ( (x2, y2, round (dist (x1, y1, x2, y2), 3), treats + 1) )

print max_treats
