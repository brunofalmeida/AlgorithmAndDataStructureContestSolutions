#include <iostream>

using namespace std;

int main() {
    long long min = 1;
    long long max = 2000000000;
    
    while (true) {
        long long guess = (min + max) / 2;
        
        cout << guess << endl;
        cout.flush();
        
        string response;
        cin >> response;
        if (response == "FLOATS")
            max = guess;
        else if (response == "SINKS")
            min = guess + 1;
        else
            break;
    }
    
    return 0;
}
