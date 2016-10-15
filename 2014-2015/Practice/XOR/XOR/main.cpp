#include <iostream>

using namespace std;

int main() {
    int T;  // number of test cases
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int S, F;
        cin >> S; cin >> F;
        
        int num = S;
        
        for (int n = S + 1; n <= F; n++)
            num = num^n;
        
        cout << num << endl;
    }
    
    return 0;
}
