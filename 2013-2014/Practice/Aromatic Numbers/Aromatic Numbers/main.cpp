#include <iostream>
#include <map>
using namespace std;

int main () {
    map <char, int> roman;
    roman ['I'] = 1;
    roman ['V'] = 5;
    roman ['X'] = 10;
    roman ['L'] = 50;
    roman ['C'] = 100;
    roman ['D'] = 500;
    roman ['M'] = 1000;
    string number;
    int total = 0;
    
    cin >> number;
    
    
    for (int i = 0; i <= number.length () - 4; i += 2) {
        if (roman [number [i + 1]] >= roman [number [i + 3]] )
            total += int (number [i] - '0') * roman [number [i + 1]];
        else
            total -= int (number [i] - '0') * roman [number [i + 1]];
    }
    total += int (number [number.length () - 2] - '0') * roman [number [number.length () - 1]];
    
    cout << total << endl;
    
    
    return 0;
}