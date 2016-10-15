#include <iostream>
using namespace std;

int main () {
    int N;
    cin >> N;
    
    if (N == 1)
        cout << 2 << endl;
    else if (N % 2 == 0)
        cout << (N / 2 + 1) * (N / 2 + 1) << endl;
    else
        cout << ( (N - 1) / 2 + 1) * ( (N - 1) / 2 + 2) << endl;
    
    return 0;
}