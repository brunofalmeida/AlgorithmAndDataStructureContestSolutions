grid = []
for y in range(3):
    grid.append( list( raw_input().strip() ) )

if (grid[0][0] == grid[0][1] == grid[0][2] == "O") or \
    (grid[1][0] == grid[1][1] == grid[1][2] == "O") or \
    (grid[2][0] == grid[2][1] == grid[2][2] == "O") or \
    (grid[0][0] == grid[1][0] == grid[2][0] == "O") or \
    (grid[0][1] == grid[1][1] == grid[2][1] == "O") or \
    (grid[0][2] == grid[1][2] == grid[2][2] == "O") or \
    (grid[0][0] == grid[1][1] == grid[2][2] == "O") or \
    (grid[0][2] == grid[1][1] == grid[2][0] == "O"):
    griffy = True
else:
    griffy = False

if (grid[0][0] == grid[0][1] == grid[0][2] == "X") or \
    (grid[1][0] == grid[1][1] == grid[1][2] == "X") or \
    (grid[2][0] == grid[2][1] == grid[2][2] == "X") or \
    (grid[0][0] == grid[1][0] == grid[2][0] == "X") or \
    (grid[0][1] == grid[1][1] == grid[2][1] == "X") or \
    (grid[0][2] == grid[1][2] == grid[2][2] == "X") or \
    (grid[0][0] == grid[1][1] == grid[2][2] == "X") or \
    (grid[0][2] == grid[1][1] == grid[2][0] == "X"):
    timothy = True
else:
    timothy = False

if griffy and timothy:
    print "Error, redo"
elif (not griffy) and (not timothy):
    print "Tie"
elif griffy:
    print "Griffy"
elif timothy:
    print "Timothy"
