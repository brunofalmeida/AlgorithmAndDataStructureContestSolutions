counter = input ()

for y in range (counter):
    i = raw_input ()
    x, p = i.split ()
    x = float (x)
    p = int (p)

    print format (x ** p, ".2f")
