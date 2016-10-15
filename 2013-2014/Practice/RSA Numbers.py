def is_RSA (n):
    counter = 0
    for x in range (1, n + 1):
        if n % x == 0:
            counter += 1
            
    if counter == 4:
        return True
    else:
        return False

low = int (raw_input ())
high = int (raw_input ())

counter =  0
for x in range (low, high + 1):
    if is_RSA (x):
        counter += 1

print "The number of RSA numbers between", low, "and", high, "is", counter
