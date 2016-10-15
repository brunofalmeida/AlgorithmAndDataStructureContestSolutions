from math import sqrt

def isPrime(num):
    if num == 1:
        return False
    else:
        isPrime = True
        for factor in range(2, int(sqrt(num)) + 1):
            if num % factor == 0:
                isPrime = False
                break
        return isPrime

N = int(raw_input())

for i in range(N):
    a, b = map(int, raw_input().strip().split())
    counter = 0

    for num in range(a, b):
        if isPrime(num):
            counter += 1

    print counter
