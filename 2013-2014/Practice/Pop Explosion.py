[p, a, y, b] = raw_input ().split ()
p = float (p)
p /= 100.0
a = int (a)
y = int (y)
b = int (b)
pop = a
counter = 0

while pop < b:
    pop += pop * p
    counter += 1

print y + counter
