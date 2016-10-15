def modInverse():
    for n in range(1, m):
        if (x * n) % m == 1:
            print n
            return

    print "No such integer exists."

x = int(raw_input())
m = int(raw_input())

modInverse()
