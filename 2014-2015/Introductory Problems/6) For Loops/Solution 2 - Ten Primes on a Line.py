M = int(raw_input())

numPrimes = 0
number = 2

while numPrimes < M:
    isPrime = True
    for factor in range(2, number):
        if number % factor == 0:
            isPrime = False

    if isPrime:
        numPrimes += 1
        if numPrimes % 10 == 0: # print primes ten to a line, so each tenth number creates a new line
            print number
        else:
            print number,

    number += 1
