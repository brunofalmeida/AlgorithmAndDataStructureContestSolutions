# It's recommended to define a function that determines if a number is prime,
# but you could put the code inside the main program

# Here are 2 possible versions of the prime function,
# a simple version and an optimized (faster) version


# Version 1:
# The function is named isPrime
# It accepts 1 input, a variable called number
# It returns True if the number is prime, or False if it isn't
def isPrime(number):
    
    # If the number is equal to 1, we know it's not prime and return False
    if number == 1:
        return False

    # Otherwise, check all possible divisors
    else:

        # Loop through the numbers from 2 to number - 1 to check for divisors
        # (range() stops at the number before the second input)
        for factor in range(2, number):

            # If the number divided by the factor has a remainder of 0
            # (divides evenly), return False because it's not a prime number
            # (The modulus operator % returns the remainder of division)
            if number % factor == 0:
                return False

        # We know that if we returned False before,
        # the function would have stopped at that point

        # If we went through all possible divisors and none were found,
        # this line will execute and return True because the number is prime
        return True


# Version 2:
# Optimized - runs faster than the previous version - only 1 difference
def isPrime(number):
    
    if number == 1:
        return False

    else:
        # This is the only difference
        # We only check divisors up to the square root of the number
        # Less numbers to check - runs faster on the computer!
        
        # number to the power of 0.5 is the same as square rooting it
        # After square rooting, we convert it to an integer with int()
        # Add 1 because range() goes up to the number before the second input
        for factor in range(2, int(number ** 0.5) + 1):
            if number % factor == 0:
                return False
            
        return True




# Main Program

# Input the integer T
T = int( raw_input() )

# Use a for loop to loop T times
for i in range(T):

    # Each time through the loop, input an integer N
    N = int( raw_input() )

    # Call the function isPrime() with N as the number input
    # Store the boolean result in an answer variable
    answer = isPrime(N)

    # We need to output 0 or 1, so convert the isPrime boolean to an integer
    # The int() function will return 1 for True or 0 for False
    # Then print the result!
    print int(answer)
