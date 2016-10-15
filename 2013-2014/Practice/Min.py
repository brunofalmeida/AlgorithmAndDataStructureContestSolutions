counter = input ()

numbers = []

for x in range (counter):
    numbers.append (input ())

numbers.sort ()

print format (numbers [0], ".2f")
