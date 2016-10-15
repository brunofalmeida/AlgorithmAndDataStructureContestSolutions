#include <iostream>
using namespace std;

int main() {
    
    /*
     Make the while condition always true
     (Keep looping until we break from inside the loop)
     */
    while (true) {
        
        // Input the word as a string
        string word;
        cin >> word;
        
        /*
         Check if the word is "quit!" - break out of the while loop if it is
         ("quit!" is spelled exactly as stated in the problem -
         lowercase letters, exclamation point)
         */
        if (word == "quit!") {
            break;
        }
        
        /*
         Create a string variable containing all possible vowels
         (Used to check for consonants later)
         */
        string vowels = "aeiouy";
        
        
        /*
         Check the 3 conditions for American spelling
         Uses && (and) to combine expressions - all conditions must be true to execute
         
         1. Get the length of the word and check if it's more than 4
         
         2. Get the third last letter
         (word.length() - 1 is the index of the last letter,
         so word.length() - 3 is the index of the third last letter,
         meaning word[ word.length() - 3 ] gets the third last letter)
         
         Then, check if the letter is a consonant
         (Is not found in the string containg all possible vowels)
         (The find() function returns a constant called string::npos if it isn't found)
         
         3. Check if the word ends with "or"
         (The substr() function will return a substring,
         starting at index word.length() - 2 and containing 2 characters,
         which will be the last 2 characters in the string)
         */
        
        if (
            (word.length() > 4) &&
            (vowels.find( word[ word.length() - 3 ] ) == string::npos) &&
            (word.substr( word.length() - 2, 2 ) == "or")
            ) {
            
            /*
             If all the conditions are true, this will run
             Output the word and replace "or" with "our"
             
             The replace() function will return a new string,
             replacing a portion of the old string
             
             replace() starts at index word.length() - 2,
             removes 2 characters,
             and replaces them with "our"
             */
            cout << word.replace(word.length() - 2, 2, "our") << endl;
        }
        
        else {
            
            /*
             If any of the conditions are false, this will run
             Output the word as it is
             */
            cout << word << endl;
        }
    }
    
    return 0;
}
