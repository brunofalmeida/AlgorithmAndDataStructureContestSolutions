DEBUG = True

import random

flooring = int (raw_input ())
r = int (raw_input ())      # height
c = int (raw_input ())      # width

grid = [[None for i in xrange (r)] for j in xrange (c)]
spaces = []     # for starting in a new room
rooms = []
visited = [[False for i in xrange (r)] for j in xrange (c)]

for y in range (r):
    row = raw_input ().strip ()
    for x in range (c):
        grid [x] [y] = row [x]
        if row [x] == ".":
            spaces.append ((x, y))

if DEBUG:
    print "Grid:"
    for y in range (r):
        for x in range (c):
            print grid [x] [y],
        print

while len (spaces) > 0:
    if DEBUG:
        print "Spaces:", spaces
        print "Rooms:", rooms

    if DEBUG:
        print "xx yy:", xx, yy
    
    stack = [spaces [0] [:]]
    area = 0

    while len (stack) > 0:
        if DEBUG:
            print "Stack:", stack
            
        (x, y) = stack.pop ()

        if DEBUG:
            print "x y:", x, y

        for (dx, dy) in ((0, -1), (1, 0), (0, 1), (-1, 0)):
            if 0 <= x + dx <= c - 1 and 0 <= y + dy <= r - 1 \
               and grid [x + dx] [y + dy] == "." and not visited [x + dx] [y + dy]:
                stack.append ((x + dx, y + dy))

        visited [x] [y] = True
        spaces.remove ((x, y))
        area += 1

    rooms.append (area)

rooms.sort ()
rooms.reverse ()

for n in range (1, len (rooms) + 1):
    if sum (rooms [: n]) > flooring:
        print n - 1, "rooms,", flooring - sum (rooms [: n]), "square metre(s) left over"
        break
else:
    print len (rooms), "rooms,", flooring - sum (rooms), "square metre(s) left over"
