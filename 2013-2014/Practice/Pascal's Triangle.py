triangle = []
counter = input ()

for x in range (1, counter + 1):
    row = [1]
    if x >= 2:
        if x >= 3:
            for y in range (x - 2):
                row.append (triangle [x - 2] [y] + triangle [x-2] [y + 1])
        row.append (1)
    triangle.append (row)

for x in triangle:
    for y in x:
        print y,
    print

#     1
#    1 1
#   1 2 1
#  1 3 3 1
# 1 4 6 4 1
