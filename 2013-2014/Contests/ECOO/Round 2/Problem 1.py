infile = open ("DATA12.txt", "r")

for z in range (10):
    grid = []
    num_questions = 0
    for i in range (9):
        inp = infile.readline ().strip ()
        if inp == "?":
            grid.append ("?")
            num_questions += 1
        else:
            grid.append (int (inp [1:]))

    possible = []

    for m in (1, 2, 5, 10, 50, 100, 1000, 10000, 500000, 1000000):
        if grid.count (m) >= 3:
            print "$" + str (m)
            break
        if grid.count (m) + num_questions >= 3:
            possible.append (m)

    else:
        if len (possible) == 0:
            print "No Prizes Possible"
        else:
            possible.sort ()
            for p in possible [:-1]:
                print "$" + str (p),
            print "$" + str (possible [-1])

infile.close ()
