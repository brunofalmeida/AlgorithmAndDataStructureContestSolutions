#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int N;
    cin >> N;
    
    int sizes [N];
    for (int i = 0; i < N; i ++) {
        cin >> sizes [i];
    }
    
    sort (sizes, sizes + N);
    
    cout.setf (ios::fixed);
    cout.precision (1);
    
    if (N % 2 == 0)
        cout << double ( (sizes [N / 2 - 1] + sizes [N / 2]) / 2.0) << endl;
    else
        cout << double (sizes [N / 2]) << endl;
    
    
    return 0;
}