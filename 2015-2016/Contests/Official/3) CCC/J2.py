square = []

for i in range(4):
    # raw_input() gets the line of input
    # .strip() removes "garbage" newline characters
    # .split() splits the input string into a list of strings, e.g. "16 3 2 13" -> ["16", "3", "2", "13"]
    # map(int, ...) converts the list of strings to a list of ints, e.g. ["16", "3", "2", "13"] -> [16, 3, 2, 13]
    # Now, we have a list of ints which can be properly added to the square
    row = map( int, raw_input().strip().split() )

    square.append(row)

# When we access numbers from the square (a 2D array), it will be [row][column]




# Start by assuming the square is magic
isMagic = True

# Get the expected sum (of row 0, the first row) to compare to the other sums
expectedSum = square[0][0] + square[0][1] + square[0][2] + square[0][3]


# Analyze rows 1-3 (4 not included in the range)
for row in range(1, 4):
    # If the sum of the current row is not the same as the expected sum, the square isn't magic
    if square[row][0] + square[row][1] + square[row][2] + square[row][3] != expectedSum:
        isMagic = False

# Analyze columns 0-3 (4 not included in the range)
for col in range(0, 4):
    # If the sum of the current column is not the same as the expected sum, the square isn't magic
    if square[0][col] + square[1][col] + square[2][col] + square[3][col] != expectedSum:
        isMagic = False




if isMagic:
    print "magic"
else:
    print "not magic"
