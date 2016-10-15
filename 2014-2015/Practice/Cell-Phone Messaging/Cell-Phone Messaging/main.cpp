#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string keys[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string presses[] = {"adgjmptw", "behknqux", "cfilorvy", "sz"};
    
    
    while (true)
    {
        // get user input
        string word;
        cin >> word;
        if (word == "halt")
            break;
        
        int seconds = 0;    // answer
        
        
        for (int i = 0; i < word.length(); i++)     // check each letter in word
        {
            // check for repeated keys
            if (i > 0)
            {
                for (int k = 0; k < 8; k++)     // check each set of keys
                {
                    if (keys[k].find(word[i]) != string::npos)  // find which key letter is on
                    {
                        if (keys[k].find(word[i - 1]) != string::npos)  // if previous letter is on same ke
                            seconds += 2;
                        else
                            break;
                    }
                }
            }
            
            for (int p = 0; p < 4; p++)     // check each set of press numbers
            {
                if (presses[p].find(word[i]) != string::npos)
                {
                    seconds += p + 1;
                    break;
                }
            }
        }
        
        
        cout << seconds << endl;
    }
    
    
    return 0;
}
