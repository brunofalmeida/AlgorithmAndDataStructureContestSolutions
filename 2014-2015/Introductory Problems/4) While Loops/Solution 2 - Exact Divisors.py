num = int(raw_input() )

divisor = 1
while divisor <= num:
    if num % divisor == 0:
        print divisor
    
    divisor += 1
