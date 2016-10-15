##def move (config, index, direction):    
##    config [index - 1 + direction].append (config [index - 1].pop () )
##        
##def canMove (config, index, direction):
##    if len (config [index - 1]) == 0:
##        return False
##    if index == 1 and direction == -1:
##        return False
##    if index == len (config) and direction == 1:
##        return False
##    if config [index - 1] > config [index - 1 + direction]:
##        return False
##
##    return True
##
##def numMoves (config):
##    for i, p in enumerate (config):
##        if [i + 1] != p:
##            break
##    else:
##        return 0
##
##    moves = []
##
##    for i, p in enumerate (config):
##        if len (p) >= 1:
##            for d in (-1, 1):
##                if canMove (config, i + 1, d):
##                    if 
##                    num = numMoves (config)
##                    if num != "IMPOSSIBLE":
##                        moves.append (num)
##
##    if moves == []:
##        return "IMPOSSIBLE"
##    else:
##        return min (moves)
##            
##            
##
##while True:
##    n = int (raw_input () )
##    if n == 0:
##        break
##
##    inp = map (int, raw_input ().strip ().split () )
##    config = []
##    for x in inp:
##        config.append ([x])
##    
##    print numMoves (config)




from collections import deque

DEBUG = False


def move (row, index, direction):
    ''' -1 is left, 1 is right '''
    row_new = row [:]
    row_new [index + direction].append (row [index].pop () )
    return row_new

def isCorrect (row):
    for i, p in enumerate (row):
        if i > 0 and [i] != p:
            break
    
    else:
        return True
    
    return False

def getMoves (row):
    queue = deque ( [ (row, 0) ] )
    while len (queue) > 0:
        if DEBUG:
            print "Queue:", queue
            
        (row, moves) = queue.popleft ()

        if DEBUG:
            print "Row:", row
            print "Moves:", moves
            print "Queue after pop:", queue
        
        if isCorrect (row):
            return moves
        
        for i in range (1, len (row)):
            if DEBUG:
                print "Row index:", i
            if len (row [i]) >= 1:
                if i == 1:
                    row_temp = row [:]
                    move (row_temp, i, 1)
                    queue.append ( (move (row_temp, i, 1), moves + 1) )

                elif i == len (row) - 1:
                    row_temp = row [:]
                    move (row_temp, i, -1)
                    queue.append ( (row_temp, moves + 1) )

                else:
                    if row [i - 1] == [] or row [i] [-1] < row [i - 1] [-1]:
                        row_temp = row [:]
                        move (row_temp, i, -1)
                        queue.append ( (row_temp, moves + 1) )

                    if row [i + 1] == [] or row [i] [-1] < row [i + 1] [-1]:
                        row_temp = row [:]
                        move (row_temp, i, 1)
                        queue.append ( (row_temp, moves + 1) )

    return None
        

while True:
    n = int (raw_input ())
    if n == 0:
        break

    inp = map (int, raw_input ().strip ().split () )
    row = [ [] ]

    for x in inp:
        row.append ( [x] )

    if DEBUG:
        print "Row:", row
        

    if len (row) == 2:
        print 0

    else:
        ans = getMoves (row)
        if ans == None:
            print "IMPOSSIBLE"

        else:
            print ans
