#include <iostream>
using namespace std;

int main () {
    string name;
    int n, R, S, D, value;
    
    cin >> n;
    
    if (n == 1) {
        cin >> name; cin >> R; cin >> S; cin >> D;
        cout << name << endl;
    }
    
    else if (n >= 2) {
        string name1, name2;
        int value1 = 0, value2 = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> name; cin >> R; cin >> S; cin >> D;
            value = (2 * R) + (3 * S) + (D);
            
            if ( (value > value1) or (value == value1 && name < name1) ) {
                name2 = name1;
                value2 = value1;
                name1 = name;
                value1 = value;
            }
            
            else if ( (value > value2) or (value == value2 && name < name2) ) {
                name2 = name;
                value2 = value;
            }
        }
        
        cout << name1 << endl;
        cout << name2 << endl;
    }
    
    return 0;
}