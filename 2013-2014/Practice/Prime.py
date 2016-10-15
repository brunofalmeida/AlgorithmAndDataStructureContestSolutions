import math

counter = input ()

for x in range (counter):
    number = input ()

    if number == 1:
        is_prime = False
    elif number == 2:
        is_prime = True
    else:
        is_prime = True
        for y in range (2, int (math.sqrt (number)) + 1):
            if number % y == 0:
                is_prime = False
                break

    print int (is_prime)
