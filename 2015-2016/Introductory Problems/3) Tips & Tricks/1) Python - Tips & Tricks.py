# Python - Tips & Tricks




# 1. Multiple Inputs

# Sometimes you need to input multiple pieces of data on the same line

# The .split() method converts a string with spaces into a list of strings
# (separates items where the spaces are, and discards the spaces)

# Example: The input is "A B C" (with spaces between the letters)
inputList = raw_input().split()
# inputList is now the list ["A", "B", "C"]




# 2. Multiple Assignment

# If you have a list of data and want to put each element into its own variable

# Each variable on the left is assigned to a list value on the right
# (The number of variables must equal the number of list elements)
A, B, C = ["a", "b", "c"]

# Same thing as:
A = "a"
B = "b"
C = "c"


# You can combine this with .split() in one step!

# Example:
# The input is "x y z" and you need to assign each letter to variables A, B, C
A, B, C = raw_input().split()

# raw_input().split() produces the list ["x", "y", "z"]
# The items in the list are assigned to A, B, and C
# Now, A = "x", B = "y", and C = "z"




# 3. List Type Conversion

# What if you need to input multiple numbers in the same line?
# (Assume they are integers for now, but this can also be applied to floats)

# The .split() method always produces a list of strings,
# so we need to convert the entire list to integers

# The map() function takes a list of one data type
# and converts all the elements to another data type

# 2 parameters to map():
# first  - the new data type
# second - the list of data

# Simple example of map():

# A list of strings
strList = ["1", "2", "3"]

# Convert all the strings in strList to int
intList = map(int, strList)
# intList is now [1, 2, 3] - all integers


# You can combine this with .split() and multiple assignment in one step!

# Example:
# The input is "1 2 3" and you need to assign each value to variables A, B, C
# (A, B, and C must be integer values instead of strings)
A, B, C = map( int, raw_input().split() )

# raw_input().split() produces the list ["1", "2", "3"] (list of strings)
# map() converts each element in the list to an integer - new list [1, 2, 3]
# The items in the integer list are assigned to A, B, and C
# Now, A = 1, B = 2, C = 3 (integers)
