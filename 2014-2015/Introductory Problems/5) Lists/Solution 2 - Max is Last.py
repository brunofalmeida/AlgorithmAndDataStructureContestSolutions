N = int( raw_input() )

numbers = []
i = 0
while i < N:
    numbers.append(  float( raw_input() )  )
    i += 1

largest = max(numbers)

i = 0
while i < N:    # output all numbers (except largest number)
    if numbers[i] != largest:
        print format( round(numbers[i], 2), ".2f" )     # round and format number to 2 decimal places
    i += 1
    
print format( round(largest, 2), ".2f" )    # output largest number
