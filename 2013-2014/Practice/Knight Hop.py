from collections import deque

board = [ [None for i in xrange (9)] for j in xrange (9) ]
moves = [ [-2, -1], [-2, 1], [-1, -2], [-1, 2], [1, -2], [1, 2], [2, 1], [2, -1] ]
start = map (int, raw_input ().strip ().split () )
end = map (int, raw_input ().strip ().split () )
board [start [0]] [start [1]] = 0
queue = deque ([start])

while len (queue) > 0:
    x, y = queue.popleft ()
    for mx, my in moves:
        nx, ny = x + mx, y + my
        if 0 < nx < 9 and 0 < ny < 9 and board [nx] [ny] == None:
            board [nx] [ny] = board [x] [y] + 1
            queue.append ([nx, ny])

print board [end [0]] [end [1]]
