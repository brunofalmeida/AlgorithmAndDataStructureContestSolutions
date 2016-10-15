#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, size, max = 0;
    int sizes [1001] = {};
    vector<int> mode (1);
    
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> size;
        sizes [size] += 1;
    }
    
    for (int i = 0; i < 1001; i ++) {
        if (sizes [i] > max) {
            mode.resize (1);
            mode [0] = i;
            max = sizes [i];
        }
        else if (sizes [i] == max && max != 0) {
            mode.resize (mode.size () + 1);
            mode [mode.size () - 1] = i;
        }
    }
    
    cout << mode.size () << endl;
    for (int i = 0; i < mode.size (); i ++)
        cout << mode [i] << endl;
    
    
    return 0;
}

