def is_prime (num):
    if num == 1:
        return False
    elif num == 2:
        return True
    else:
        for y in range (2, int (num ** 0.5) + 1):
            if num % y == 0:
                return False
        return True

counter = int (raw_input () )
num_primes = 0
num = 3

if counter > 0:
    print 2,
    num_primes = 1
    
while True:
    if num_primes == counter:
        break
    
    if is_prime (num):
        print num,
        num_primes += 1
        
    if num_primes % 10 == 0 and num_primes != 0:
        print

    num += 2
