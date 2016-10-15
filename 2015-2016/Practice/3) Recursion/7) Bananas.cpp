// http://wcipeg.com/problem/ccc05j5


#include <iostream>

using namespace std;


// Declare both functions because they call each other
bool isAMonkeyWord(string word);
bool isAnAWord(string word);


/*
 Returns true if the word is a monkey word, or false if it isn't
 (Refer to the rules in the problem)
 */
bool isAMonkeyWord(string word) {
    /*
     Base case
     If the word is an A-word, it is a monkey word
     */
    if (isAnAWord(word)) {
        return true;
    }
    
    /*
     Recursive case
     Loop through every index in the word, except for the first and last letters
     */
    for (int i = 1; i < word.length() - 1; i++) {
        /*
         Check for 3 conditions (all must be true for the word to be a monkey word):
         1. The word up to (but not including) the current letter is an A-word
         2. The current letter is N
         3. The word after (but not including) the current letter is a monkey word
         */
        if (
            isAnAWord( word.substr(0, i) ) &&
            word[i] == 'N' &&
            isAMonkeyWord( word.substr(i + 1, word.length() - i - 1) )
            ) {
            return true;
        }
    }
    
    // If the checks did not find it as a monkey word, return false
    return false;
}


/*
 Returns true if the word is an A-word, or false if it isn't
 (Refer to the rules in the problem)
 */
bool isAnAWord(string word) {
    /*
     Base case
     If the word is just an A, it is an A-word
     */
    if (word == "A") {
        return true;
    }
    
    /*
     Recursive case
     Check for 4 conditions (all must be true for the word to be an A-word):
     1. The word is 3 letters or more
     2. The first letter is B
     3. The word, except for the first and last letters, is a monkey word
     4. The last letter is S
     */
    else if (
             word.length() >= 3 &&
             word[0] == 'B' &&
             isAMonkeyWord( word.substr(1, word.length() - 2) ) &&
             word[word.length() - 1] == 'S'
             ) {
        return true;
    }
    
    // If the checks did not find it as an A-word, return false
    else {
        return false;
    }
}


int main() {
    // Keep looping until we break from inside the loop
    while (true) {
        
        // Input
        string word;
        cin >> word;
        
        // If the input was X, break to stop the program
        if (word == "X")
            break;
        
        // If the monkey word function returns true, output YES
        if (isAMonkeyWord(word))
            cout << "YES" << endl;
        // If the monkey word function returned false, output NO
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
