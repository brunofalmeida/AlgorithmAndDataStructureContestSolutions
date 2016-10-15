#include <iostream>

using namespace std;


bool isMonkeyWord(string word);
bool isAWord(string word);


bool isMonkeyWord(string word)
{
    if (isAWord(word))
        return true;
    
    for (int i = 1; i < word.length() - 1; i++)
    {
        if (
            isAWord( word.substr(0, i) ) and
            word[i] == 'N' and
            isMonkeyWord( word.substr(i + 1, word.length() - i - 1) )
            )
            return true;
    }
    
    return false;
}


bool isAWord(string word)
{
    if (word == "A")
        return true;
    
    else if (
             word.length() >= 3 and
             word[0] == 'B' and
             isMonkeyWord( word.substr(1, word.length() - 2) ) and
             word[word.length() - 1] == 'S'
             )
        return true;
    
    else
        return false;
}


int main()
{
    while (true)
    {
        string word;
        cin >> word;
        
        if (word == "X")
            break;
        
        
        if (isMonkeyWord(word))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    
    return 0;
}
