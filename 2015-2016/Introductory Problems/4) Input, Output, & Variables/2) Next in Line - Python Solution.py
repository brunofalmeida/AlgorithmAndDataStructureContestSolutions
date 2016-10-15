# Input the ages of the youngest child and middle child
# You need to input integer numbers, but use int( raw_input() )
# because input() can fail on online judge testing
# (Each line takes input from raw_input() and converts it to an integer number)
youngest = int( raw_input() )
middle = int( raw_input() )

# Calculate the difference between the middle and youngest children
# (The middle child's age minus the youngest child's age)
difference = middle - youngest

# Calculate the age of the oldest child
# (The middle child's age plus the difference calculated before)
oldest = middle + difference

# Output the age of the oldest child
print oldest
