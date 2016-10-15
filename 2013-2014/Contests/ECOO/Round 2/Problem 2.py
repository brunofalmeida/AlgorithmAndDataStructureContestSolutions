def factors (n):
    l = []
    for i in range (1, int (n ** 0.5) + 1):
        if n % i == 0:
            l.append (i)
            if i != n/i:
                l.append (n/i)
    l.sort ()
    return l

def is_black (x, y, f):
    if (x % (2 * f) in range (f) and y % (2 * f) in range (f)) or \
       (x % (2 * f) not in range (f) and y % (2 * f) not in range (f)):
        return True
    return False

infile = open ("DATA21.txt", "r")

for z in range (10):
    N = int (infile.readline ().strip () )
    tiles = []
    black = []
    for i in range (5):
        [R, C] = map (int, infile.readline ().strip ().split () )
        R -= 1
        C -= 1
        tiles.append ((C, R))
        black.append (is_black (C, R, 1) )

    for n in factors (N) [1:]:
        for i in range (5):
            if is_black ( tiles [i] [0], tiles [i] [1], n):
                black [i] = not black [i]

    string = ""
    for i in range (5):
        if black [i]:
            string += "B"
        else:
            string += "G"
    print string

infile.close ()
