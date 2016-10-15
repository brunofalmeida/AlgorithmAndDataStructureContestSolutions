# Input the integer number
N = int( raw_input() )




# There are 2 ways to print the times table (for loop or while loop),
# but only use 1

# Tips:
# To comment out a block of code, select it and press Control-3
# To uncomment a block of code, select it and press Control-4


# Way 1: For Loop (recommended)

# Loop the variable i through the numbers 1 to N
# (The range() function goes from the first number to
#  ONE LESS THAN the second number,
#  so we need to use N + 1)
for i in range(1, N + 1):

    # Output a statement - combine output items with commas
    # Each comma adds a space automatically, like in the sample output
    
    # N and i are integer variables
    # (N * i) will evaluate to the multiplication answer
    # "X" and "=" are literal strings to show the multiplication statement
    print N, "X", i, "=", (N * i)


# Way 2: While Loop

# Initialize the variable factor to 1 before the loop
# (The multiplication starts at 1)
factor = 1

# Keep looping while factor is less than or equal to the end number N
while factor <= N:

    # Output a statement - combine output items with commas
    # Each comma adds a space automatically, like in the sample output
    
    # N and factor are integer variables
    # (N * factor) will evaluate to the multiplication answer
    # "X" and "=" are literal strings to show the multiplication statement
    print N, "X", factor, "=", (N * factor)

    # Add 1 to the factor before looping again
    factor += 1
