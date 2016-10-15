#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    string output;
    string none;
    
    
    cin >> T;
    
    
    for (int i = 0; i < T; i ++) {
        // initialize test case variables
        output = "No";
        vector<string> grid (4);
        
        
        // accept grid input
        for (int y = 0; y < 4; y ++) {
            cin >> grid [y];
        }
        
        
        // check rows
        for (int y = 0; y < 4; y ++) {
            if (grid [y] [0] == 'X' && grid [y] [1] == 'X' && grid [y] [2] == 'X' && grid [y] [3] == 'X') {
                output = "Yes";
                break;
            }
        }
        // check columns
        for (int x = 0; x < 4; x ++) {
            if (grid [0] [x] == 'X' && grid [1] [x] == 'X' && grid [2] [x] == 'X' && grid [3] [x] == 'X') {
                output = "Yes";
                break;
            }
        }
        // check diagonals
        if (grid [0] [0] == 'X' && grid [1] [1] == 'X' && grid [2] [2] == 'X' && grid [3] [3] == 'X') {
            output = "Yes";
        }
        if (grid [0] [3] == 'X' && grid [1] [2] == 'X' && grid [2] [1] == 'X' && grid [3] [0] == 'X') {
            output = "Yes";
        }
        
        
        // output result
        cout << output << endl;
        
        
        // skip blank line
        if (i < T - 1) {
            getline (cin, none);
        }
    }
    

    
    return 0;
}

