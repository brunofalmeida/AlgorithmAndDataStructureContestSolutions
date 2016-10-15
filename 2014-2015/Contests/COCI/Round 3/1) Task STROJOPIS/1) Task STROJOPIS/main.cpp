#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // input
    vector<int> presses(8, 0);
    
    string word;
    cin >> word;
    
    
    // search
    vector<string> characters = {"`1QAZ", "2WSX", "3EDC", "4RFV5TGB", "6YHN7UJM", "8IK,", "9OL.", "0P;/-['=]"};
    for (int i = 0; i < word.length(); i++) // for each letter
    {
        for (int set = 0; set < 8; set++)   // for each set of characters
        {
            if (characters[set].find(word[i]) != string::npos)
            {
                presses[set]++;
                break;
            }
        }
    }
    
    
    // output
    for (int i = 0; i < 8; i++)
        cout << presses[i] << endl;
    
    
    return 0;
}
