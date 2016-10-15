N = int(raw_input())

names = [0, 0, 0]
points = [0, 0, 0]

for i in range(1, N + 1):
    inp = map( int, raw_input().strip().split() )

    product = 1
    for n in inp[1:]:
        product *= n

    if product >= points[0]:
        names[2] = names[1]
        points[2] = points[1]
        names[1] = names[0]
        points[1] = points[0]
        names[0] = i
        points[0] = product

    elif product >= points[1]:
        names[2] = names[1]
        points[2] = points[1]
        names[1] = i
        points[1] = product

    elif product >= points[2]:
        names[2] = i
        points[2] = product

print names[0]
print names[1]
print names[2]
