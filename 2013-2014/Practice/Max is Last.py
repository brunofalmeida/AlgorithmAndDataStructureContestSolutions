counter = input ()
list = []

for x in range (counter):
    list.append (input ())

maximum = max (list)

for x in range (len (list)):
    if list [x] != maximum:
        print format (round (list [x], 2), ".2f")

print format (round (maximum, 2), ".2f")
