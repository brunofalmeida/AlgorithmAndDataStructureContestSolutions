from collections import deque

def getFriends (x):
    fs = []
    for i, a in enumerate (graph [x]):
        if a:
            fs.append (i)

    return fs

def makeFriends (x, y):
    graph [x] [y] = graph [y] [x] = True

def deleteFriends (x, y):
    graph [x] [y] = graph [y] [x] = False

def numFriends (x):
    print graph [x].count (True)

def numFriendsOfFriends (x):
    fs = getFriends (x)
    fof = []
    for f in fs:
        fof.extend (getFriends (f) )

    counter = len (fof)
    for f in fof:
        if f == x or f in fs:
            counter -= 1
    print counter

def separation (x, y):
    sep_graph = [None for i in xrange (50)]
    sep_graph [x] = 0
    queue = deque ([x])
    
    while len (queue) > 0:
        a = queue.popleft ()

        for b in getFriends (a):
            if sep_graph [b] == None:
                sep_graph [b] = sep_graph [a] + 1
                queue.append (b)

    return sep_graph [y]      


graph = [ [False for i in xrange (50)] for j in xrange (50) ]

makeFriends (1, 6)

makeFriends (2, 6)

makeFriends (3, 4)
makeFriends (3, 5)
makeFriends (3, 6)
makeFriends (3, 15)

makeFriends (4, 5)
makeFriends (4, 6)

makeFriends (5, 6)

makeFriends (6, 7)

makeFriends (7, 8)

makeFriends (8, 9)

makeFriends (9, 10)
makeFriends (9, 12)

makeFriends (10, 11)

makeFriends (11, 12)

makeFriends (12, 13)

makeFriends (13, 14)
makeFriends (13, 15)

makeFriends (16, 17)
makeFriends (16, 18)

makeFriends (17, 18)


while True:
    command = raw_input ().strip ()

    if command == "i":
        x = int (raw_input ())
        y = int (raw_input ())
        makeFriends (x, y)

    elif command == "d":
        x = int (raw_input ())
        y = int (raw_input ())
        deleteFriends (x, y)

    elif command == "n":
        x = int (raw_input ())
        numFriends (x)

    elif command == "f":
        x = int (raw_input ())
        numFriendsOfFriends (x)

    elif command == "s":
        x = int (raw_input ())
        y = int (raw_input ())
        
        sep = separation (x, y)
        
        if sep == None:
            print "Not connected"
        else:
            print sep

    elif command == "q":
        break
