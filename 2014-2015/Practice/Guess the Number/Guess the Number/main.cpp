#include <iostream>

using namespace std;

int main ()
{
    long long int low = 1, high = 2000000000, guess;
    string answer;
    
    do
    {
        guess = (low + high) / 2;
        
        cout << guess << endl;
        cin >> answer;
        
        if (answer == "Lower")
            high = guess;
        else if (answer == "Higher")
            low = guess + 1;
    }
    while (answer != "OK");
    
    
    return 0;
}