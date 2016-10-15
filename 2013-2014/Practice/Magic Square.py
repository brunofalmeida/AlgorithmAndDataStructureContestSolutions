def row_sum (square, index):
    total = 0
    for x in square [index]:
        total += x
        
    return total

def column_sum (square, index):
    total = 0
    for x in range (len (square)):
        total += square [x] [index]

    return total

def is_magic (square):
    is_magic = True
    
    csum = row_sum (square, 0)
    for x in range (1, N):
        if row_sum (square, x) != csum:
            return False
        
    csum = column_sum (square, 0)
    for x in range (1, N):
        if column_sum (square, x) != csum:
            return False
        
    return True


T = input ()

for x in range (T):
    N = input ()
    square = []
    for y in range (N):
        row = []
        for z in range (N):
            row.append (input ())
        square.append (row)

    if is_magic (square):
        print "yes"
    else:
        print "no"

    if x != T - 1:
        raw_input ()
