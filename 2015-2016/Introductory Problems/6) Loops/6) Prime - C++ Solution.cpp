#include <iostream>

// We need to import the cmath library to use the square root function
#include <cmath>

using namespace std;

/*
 It's recommended to define a function that determines if a number is prime,
 but you could put the code inside the main program

 Here are 2 possible versions of the prime function,
 a simple version and an optimized (faster) version
 */


/*
 Version 1:
 The function is named isPrime1
 It accepts 1 input, an integer called number
 It returns true if the number is prime, or false if it isn't
 */
bool isPrime1(int number) {
    
    // If the number is equal to 1, we know it's not prime and return false
    if (number == 1) {
        return false;
    }
    
    // Otherwise, check all possible divisors
    else {
        
        /*
         Loop through the numbers from 2 to number - 1 to check for divisors
         
         Create an integer variable named factor and start it at 2
         Keep looping while factor is less than the number
         Add 1 to factor at the end of each loop iteration
         */
        for (int factor = 2; factor < number; factor++) {
            
            /*
             If the number divided by the factor has a remainder of 0
             (divides evenly), return false because it's not a prime number
             (The modulus operator % returns the remainder of division)
             */
            if (number % factor == 0) {
                return false;
            }
        }
        
        /*
         We know that if we returned false before,
         the function would have stopped at that point
                
         If we went through all possible divisors and none were found,
         this line will execute and return true because the number is prime
         */
        return true;
    }
}


/*
 Version 2:
 Optimized - runs faster than the previous version - only 1 difference
 */
bool isPrime2(int number) {
    if (number == 1) {
        return false;
    }
    
    else {
        
        /*
          This is the only difference
          We only check divisors up to the square root of the number
          Less numbers to check - runs faster on the computer!
         
          Call the sqrt() function from the cmath library
          (see the required import statement above)
          After square rooting, we convert it to an integer with the (int) cast
         */
        for (int factor = 2; factor <= (int) sqrt(number); factor++) {
            if (number % factor == 0) {
                return false;
            }
        }
        
        return true;
    }
}




// Main Program
int main() {
    
    // Input the integer T
    int T;
    cin >> T;
    
    // Use a for loop to loop T times
    for (int i = 0; i < T; i++) {
        
        // Each time through the loop, input an integer N
        int N;
        cin >> N;
        
        // Call the function isPrime() with N as the input
        // Store the boolean result in an answer variable
        // (This calls the optimized prime function, but you could use the first version)
        bool answer = isPrime2(N);
        
        // Output the answer (will output 1 for true or 0 for false)
        cout << answer << endl;
    }
    
    return 0;
}
