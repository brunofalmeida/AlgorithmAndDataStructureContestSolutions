#include <iostream>
using namespace std;

int main () {
    int z, T, x, y, total;
    
    cin >> z;
    
    int grid [z] [z];
    for (int yy = 0; yy < z; yy++) {
        for (int xx = 0; xx < z; xx++) {
            cin >> grid [xx] [yy];
        }
    }
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> x;
        cin >> y;
        
        total = 0;
        for (int xx = 0; xx < z; xx++)
            total += grid [xx] [x - 1];
        for (int yy = 0; yy < z; yy++)
            total += grid [y - 1] [yy];
        cout << total << endl;
    }
    
    return 0;
}