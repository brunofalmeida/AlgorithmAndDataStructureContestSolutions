# Python - Common Problems




# 1. Newline Characters

# Sometimes when you input a string, garbage characters
# (like the newline character \n) remain in the string

# Solution: Use the strip() method to remove the trailing garbage characters

# bad (the garbage characters are inputted)
string = raw_input()

# good (the garbage characters are removed from the input)
string = raw_input().strip()




# 2. Inputting Numbers

# Normally you would use input() to input numbers,
# but it sometimes doesn't work with online graders
# (It has to do with the formatting of newline and return characters)

# Solution: You should always use int( raw_input() ) instead of input()
# (Gets the string from raw_input() and converts it to an int manually)
# Or use float( raw_input() ) if you need to input a float (number with decimals)

# bad
a = input()

# good
a = int( raw_input() )
# or
a = float( raw_input() )




# 3. Spaces

# By default, the print command prints a line
# and moves the following output to the next line

# Solution: Use a comma between output items
# This will output them on the same line and add a space between them
# (and no type conversion necessary!)

# Example: you need to output 1 and 2 on the same line, separated by a space

# bad (outputs "1" and "2" on separate lines by default)
print 1
print 2

# good (outputs "1 2" with a space between on the same line)
# (normally you would use variables instead of 1 and 2)
print 1, 2
