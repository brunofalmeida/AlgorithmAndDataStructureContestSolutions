# http://wcipeg.com/problem/p299ex4


def isPrime(num):
    if num == 1:
        return False
    
    else:
        for factor in range(2, num):
            if num % factor == 0:
                return False

        return True


T = int(raw_input())

for i in range(T):
    N = int(raw_input())

    if isPrime(N):
        print 1
    else:
        print 0
