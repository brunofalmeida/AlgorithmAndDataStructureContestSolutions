for i in range (int (raw_input () ) ):
    N = int (raw_input ())

    grid = [ [None for y in range (N)] for x in range (N) ]
    nums = (1, 2, 3, 4, 5)
    
    for y in range (N):
        for x in range (N):
            for n in nums:
                works = True
                for y2 in range (N):
                    if y2 != y and grid [x] [y2] == n:
                        works = False
                for x2 in range (N):
                    if x2 != x and grid [x2] [y] == n:
                        works = False

                if works:
                    grid [x] [y] = n
                    break

for y in range (N):
    for x in range (N - 1):
        print grid [x] [y],
    print grid [x] [-1]
