def fill (x, y):
    if x == M:
        opt [x] [y] = opt [x] [y + 1] + grid [x] [y]
    elif y == N:
        opt [x] [y] = opt [x + 1] [y] + grid [x] [y]
    else:      
        opt [x] [y] = max (opt [x] [y + 1], opt [x + 1] [y] ) + grid [x] [y]
        

M, N = map (int, raw_input ().strip ().split () )
grid = [ [0 for y in xrange (N + 1)] for x in xrange (M + 1) ]
while True:
    x, y = map (int, raw_input ().strip ().split () )
    if (x, y) == (0, 0):
        break
    grid [x] [y] = 1

opt = [ [0 for y in xrange (N + 1)] for x in xrange (M + 1) ]
opt [M] [N] = grid [M] [N]

x = M - 1
y = N - 1

while True:
    for y2 in range (N, y, -1):
        fill (x, y2)
        
    for x2 in range (M, x, -1):
        fill (x2, y)
        
    fill (x, y)
    
    if x == 1 or y == 1:
        break
    x -= 1
    y -= 1

if x != y:
    if y == 1:
        for x in xrange (M, 0, -1):
            fill (x, 1)
            
    elif x == 1:
        for y in xrange (N, 0, -1):
            fill (1, y)

print opt [1] [1]
