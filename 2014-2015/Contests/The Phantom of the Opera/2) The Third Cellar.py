from math import sqrt

def isPrime(num):
    if num == 1:
        return False
    else:
        if num % 2 == 0:
            return False
        for factor in range(3, int(sqrt(num)) + 1, 2):
            if num % factor == 0:
                return False
        return True


N = int(raw_input())

for i in range(N):
    a, b = map(int, raw_input().strip().split())
    counter = 0

    if a <= 2 < b:
        counter += 1
    for num in range(a + int(a % 2 == 0), b, 2):
        if isPrime(num):
            counter += 1

    print counter
