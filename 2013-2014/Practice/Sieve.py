def is_prime (n):
    if n == 1:
        return False
    elif n == 2 or n == 3:
        return True
    temp = True
    for x in range (2, n):
        if n % x == 0:
            temp = False
            break

    return temp

N = input ()

for x in range (1, N + 1):
    if is_prime (x):
        print 1
    else:
        print 0
