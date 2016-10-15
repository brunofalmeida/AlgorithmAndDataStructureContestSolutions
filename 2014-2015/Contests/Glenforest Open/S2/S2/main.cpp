#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // input
    int N;
    cin >> N;
    
    vector<string> goodWords(N);
    vector<string> badWords(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> goodWords[i]; cin >> badWords[i];
    }
    
    
    // algorithm
    string speech;  // for output
    
    bool go = true;
    while (go)
    {
        string word;
        cin >> word;
        
        if (word[word.length() - 1] == '.')
        {
            go = false;
            word = word.substr(0, word.length() - 1);
        }
        
        for (int i = 0; i < N; i++)
        {
            if (word == badWords[i])
            {
                word = goodWords[i];
                break;
            }
        }
        
        if (! go)
            speech += word + ".";
        else
            speech += word + " ";
    }
    
    
    // output
    cout << speech << endl;
    
    
    return 0;
}
