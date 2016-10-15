numWins = 0

for i in range(6):
    # The program only seems to work if you use .strip() on raw_input()
    # (.strip() removes newline "garbage" characters from the input)
    if raw_input().strip() == 'W':
        numWins += 1

if numWins == 5 or numWins == 6:
    print 1
elif numWins == 3 or numWins == 4:
    print 2
elif numWins == 1 or numWins == 2:
    print 3
else:
    print -1
