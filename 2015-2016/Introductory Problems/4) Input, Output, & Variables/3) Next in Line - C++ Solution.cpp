#include <iostream>
using namespace std;

int main() {
    // Declare integer variables to store the ages of the youngest and middle children
    int youngest;
    int middle;
    
    // Input the ages of the youngest and middle children
    cin >> youngest;
    cin >> middle;
    
    // Declare and calculate a variable for the difference between the middle and youngest children
    // (The middle child's age minus the youngest child's age)
    int difference = middle - youngest;

    // Declare and calculate the age of the oldest child
    // (the middle child's age plus the difference calculated before)
    int oldest = middle + difference;
    
    // Output the age of the oldest child
    // (Add the endl to output the number on its own line)
    cout << oldest << endl;
    
    return 0;
}
