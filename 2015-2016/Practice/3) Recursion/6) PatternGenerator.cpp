// http://wcipeg.com/problems/desc/ccc96s3


#include <iostream>

using namespace std;


/*
 base - the bit pattern we have so far
 n - number of bits left to add
 k - number of 1 bits left to add
 */
void pattern(string base, int n, int k) {
    
    /*
     Base case
     There are no more bits left to add, so print out the pattern we have
     */
    if (n == 0) {
        cout << base << endl;
    }
    
    /*
     If the number of total bits left to add equals the number of 1 bits left to add
     (all the bits left to add are 1s)
     
     Add a 1 to the string we have so far and recurse
     (Decrease both n and k by 1 because we used a 1 bit,
      which counts towards the total number of bits and number of 1 bits)
     */
    else if (n == k) {
        pattern(base + "1", n - 1, k - 1);
    }
    
    /*
     If the number of 1 bits left to add is 0
     (all the bits left to add are 0s)
     
     Add a 0 to the string we have so far and recurse
     (Decrease only n by 1 because we used a 0 bit,
      which only counts towards the total number of bits)
     */
    else if (k == 0) {
        pattern(base + "0", n - 1, k);
    }
    
    /*
     Otherwise, recurse using both 1 and 0 (in separate recursive statements)
     We can add a 1 or a 0, but use the 1 first since the problem says descending order
     */
    else {
        pattern(base + "1", n - 1, k - 1);
        pattern(base + "0", n - 1, k);
    }
}


int main() {
    // Input
    int numPairs;
    cin >> numPairs;
    
    // Loop
    for (int i = 0; i < numPairs; i++) {
        
        // Input
        int n, k;
        cin >> n >> k;
        
        // Must output this statement first, according to the problem output specification
        cout << "The bit patterns are" << endl;
        
        // Start recursing
        // (Starts with an empty string and the original n and k values)
        pattern("", n, k);
        
        // Output a blank line between cases
        cout << endl;
    }
    
    return 0;
}
