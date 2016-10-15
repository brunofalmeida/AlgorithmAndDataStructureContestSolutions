N, M, Y = raw_input ().strip ().split ()

N = float (N)
M = float (M) / 100
Y = int (Y)

print 0, format (N, ".2f")
for y in range (1, Y + 1):
    N += M * N
        
    print y, format (N, ".2f")
