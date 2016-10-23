# (Same as problem S2)


question = int(raw_input())
N = int(raw_input())

# raw_input() gets the line of input
# .strip() removes "garbage" newline characters
# .split() splits the input string into a list of strings, e.g. "5 1 4" -> ["5", "1", "4"]
# map(int, ...) converts the list of strings to a list of ints, e.g. ["5", "1", "4"] -> [5, 1, 4]
# Now, we have a list of ints
dmoj = map(int, raw_input().strip().split())
peg = map(int, raw_input().strip().split())

# Sort both lists from lowest to highest
dmoj.sort()
peg.sort()

# Create a list, for pairs of riders
pairs = []




# Minimize total speed
# (optimal strategy: pair up the two fastest riders)
if question == 1:

    # Loop for the number of riders
    for i in range(N):
        # Get the fastest rider in each list and remove it from the list
        a = dmoj.pop(-1)
        b = peg.pop(-1)

        # Add to the list of pairs (note the inner brackets to create a pair)
        pairs.append( (a, b) )


# Maximize total speed
# (optimal strategy: pair up the fastest rider with the slowest rider)
elif question == 2:

    # Loop for the number of riders
    for num in range(N):
        # Get the fastest item in each list (don't remove them yet!)
        a = dmoj[-1]
        b = peg[-1]

        # Find which rider is faster, and pair them up with the slowest rider in the opposite list
        if a > b:
            a = dmoj.pop(-1)
            b = peg.pop(0)
        else:
            a = dmoj.pop(0)
            b = peg.pop(-1)

        # Add to the list of pairs (note the inner brackets to create a pair)
        pairs.append( (a, b) )




# Find the total sum by adding the fastest rider in each pair
sum = 0
for pair in pairs:
    sum += max(pair[0], pair[1])
print sum
