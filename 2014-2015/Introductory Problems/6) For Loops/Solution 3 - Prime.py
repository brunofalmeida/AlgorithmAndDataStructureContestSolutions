import math     # include math-related functions (need square root)

T = int(raw_input())

for i in range(T):
    N = int(raw_input())

    if N == 1:
        isPrime = False
    else:
        isPrime = True
        for factor in range(2, int(math.sqrt(N)) + 1):   # must only check factors up to square root
            if N % factor == 0:
                isPrime = False

    print int(isPrime)
