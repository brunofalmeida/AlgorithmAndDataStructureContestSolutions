#include <iostream>

// We need to import the vector library to use it
#include <vector>

using namespace std;


int main() {
    // Create the playlist (a vector list of characters) - characters go in single quotes
    vector<char> plist = {'A', 'B', 'C', 'D', 'E'};
    
    
    /*
     Keep looping - make the condition always true
     The program will break out of the loop from inside it
     */
    while (true) {
        
        // Input the two numbers: b (button) and n (number of times to press)
        int b;
        cin >> b;
        
        int n;
        cin >> n;
        
        /*
         If b is 4 and n is 1,
         stop rearranging songs and break out of the while loop
         */
        if (b == 4 && n == 1) {
            break;
        }
        
        // Loop n times (the button is pressed n times)
        for (int i = 0; i < n; i++) {
            
            /*
             Make a copy of the playlist to preserve its old state
             
             The vector constructor (creator) can accept an existing vector between the round brackets
             It will copy the contents of the existing vector into the new vector
             */
            vector<char> plistOld(plist);
            
            // Check the button number and perform the appropriate action
            
            // Button 1 - move the first song to the end
            if (b == 1) {
                
                /*
                 The numbers in square brackets [] access an index in the vector (list)
                 Remember: the first index is always 0!
                 e.g. plist[0] is the first item in plist, plist[1] is the second
                 */
                
                plist[0] = plistOld[1];
                plist[1] = plistOld[2];
                plist[2] = plistOld[3];
                plist[3] = plistOld[4];
                plist[4] = plistOld[0];
            }
            
            // Button 2 - move the last song to the start
            else if (b == 2) {
                plist[0] = plistOld[4];
                plist[1] = plistOld[0];
                plist[2] = plistOld[1];
                plist[3] = plistOld[2];
                plist[4] = plistOld[3];
            }
            
            // Button 3 - swap the first two songs
            else if (b == 3) {
                plist[0] = plistOld[1];
                plist[1] = plistOld[0];
            }
        }
    }
    
    
    // After breaking out of the loop, output the final playlist
    // (Remember to add spaces between each item and an endl at the end)
    cout << plist[0] << " " << plist[1] << " " << plist[2] << " " << plist[3] << " " << plist[4] << endl;
    
    
    return 0;
}
