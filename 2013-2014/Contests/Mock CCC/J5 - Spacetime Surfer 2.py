from collections import deque


def isValidPoint (maps, t, y, x):
    if 0 < t <= T and 0 < y <= R and 0 < x <= C and maps [t] [y] [x] != "X":
        return True
    return False


[R, C, T] = map (int, raw_input ().strip ().split () )
# array [T] [R] [C] - 3 dimensions - time, y, x
maps = [None]

for i in range (T):     # each map
    m = [None]
    for j in range (R):
        m.append ( [None] + list (raw_input () ) )
    maps.append (m)

# Find Alice's position
for t in range (1, T + 1):
    for y in range (1, R + 1):
        for x in range (1, C + 1):
            if maps [t] [y] [x] == "A":
                A = (t, y, x)

# Find Bob's position
for t in range (1, T + 1):
    for y in range (1, R + 1):
        for x in range (1, C + 1):
            if maps [t] [y] [x] == "B":
                B = (t, y, x)


# BFS
queue = deque ( [ ( (A [0], A [1], A [2] ), 0) ] )
distances = [ [ [None for i in range (C + 1) ] for j in range (R + 1) ] for k in range (T + 1) ]
distances [A [0]] [A [1]] [A [2]] = 0

while len (queue) > 0:
    ( (t, y, x), seconds) = queue.popleft ()

    if (t, y, x) == B:
        break


    for i in range (1, T + 1):
        if i != t:
            if isValidPoint (maps, i, y, x) and distances [i] [y] [x] == None:
                distances [i] [y] [x] = seconds + 1
                queue.append ( ( (i, y, x), seconds + 1) )


    if isValidPoint (maps, t, y - 1, x) and distances [t] [y - 1] [x] == None:
        distances [t] [y - 1] [x] = seconds + 1
        queue.append ( ( (t, y - 1, x), seconds + 1) )
        
    if isValidPoint (maps, t, y + 1, x) and distances [t] [y + 1] [x] == None:
        distances [t] [y + 1] [x] = seconds + 1
        queue.append ( ( (t, y + 1, x), seconds + 1) )


    if isValidPoint (maps, t, y, x - 1) and distances [t] [y] [x - 1] == None:
        distances [t] [y] [x - 1] = seconds + 1
        queue.append ( ( (t, y, x - 1), seconds + 1) )
        
    if isValidPoint (maps, t, y, x + 1) and distances [t] [y] [x + 1] == None:
        distances [t] [y] [x + 1] = seconds + 1
        queue.append ( ( (t, y, x + 1), seconds + 1) )

if distances [B [0]] [B [1]] [B [2]] == None:
    print -1
else:
    print distances [B [0]] [B [1]] [B [2]]
