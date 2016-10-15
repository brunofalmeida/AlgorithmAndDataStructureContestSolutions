#include <iostream>
#include <map>
using namespace std;

int main () {
    int k, a = 0, length = 1;
    string character, code, output = "", sequence;
    map <string, string> codes;
    
    
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> character;
        cin >> code;
        codes [code] = character;
    }
    cin >> sequence;
    
    while (a < sequence.length ()) {
        if (codes.find (sequence.substr (a, length) ) != codes.end () ) {
            output += codes [sequence.substr (a, length) ];
            a += length;
            length = 1;
        }
        
        else {
            length += 1;
        }
    }
    
    cout << output << endl;
    
    
    return 0;
}