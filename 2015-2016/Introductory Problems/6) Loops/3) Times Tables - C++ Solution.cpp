#include <iostream>
using namespace std;

int main() {
    // Input the integer number
    int N;
    cin >> N;
    
    
    
    
    /*
     There are 2 ways to print the times table (for loop or while loop),
     but only use 1
        
     Tips:
     
     To comment out a block of code, select it and press
     Control-Shift-C (on CodeBlocks) or Command-/ (on Xcode)
     
     To uncomment a block of code, select it and press
     Control-Shift-X (on CodeBlocks) or Command-/ (on Xcode)
     */
    
    
    // Way 1: For Loop (recommended)
    
    /*
     Create the variable i with a starting value of 1
     Keep looping while i is less than or equal to the end number N
     Increase i by 1 at the end of each loop iteration
     */
    for (int i = 1; i <= N; i++) {
        /*
         Output a statement - combine output items with <<
         Remember to add spaces where necessary, like in the sample output
                
         N and i are integer variables
         (N * i) will evaluate to the multiplication answer
         " X " and " = " are literal strings (with necessary spaces) to show the multiplication statement
         endl makes sure that each cout operation goes on its own line
         */
        cout << N << " X " << i << " = " << (N * i) << endl;
    }
    
    
    // Way 2: While Loop (recommended)
    
    // Initialize the variable factor to 1 before the loop
    // (The multiplication starts at 1)
    int factor = 1;
    
    // Keep looping while factor is less than or equal to the end number N
    while (factor <= N) {
        /*
         Output a statement - combine output items with <<
         Remember to add spaces where necessary, like in the sample output
         
         N and factor are integer variables
         (N * factor) will evaluate to the multiplication answer
         " X " and " = " are literal strings (with necessary spaces) to show the multiplication statement
         endl makes sure that each cout operation goes on its own line
         */
        cout << N << " X " << factor << " = " << (N * factor) << endl;
        
        // Add 1 to the factor before looping again
        factor++;
    }
    
    
    
    
    return 0;
}
