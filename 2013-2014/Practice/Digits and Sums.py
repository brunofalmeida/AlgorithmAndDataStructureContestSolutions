[m, n] = raw_input ().split ()
m = int (m)
n = int (n)

for x in range (m, n + 1):
    a = int (str (x) [0])
    b = int (str (x) [1])
    c = int (str (x) [2])

    if a ** 3 + b ** 3 + c ** 3 == x:
        print x
