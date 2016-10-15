#include <iostream>
using namespace std;

int main () {
    int N, first, previous, current, max = 0;
    cin >> N;
    
    cin >> current;
    first = current;
    for (int i = 1; i < N; i ++) {
        previous = current;
        cin >> current;
        if (previous * current > max)
            max = previous * current;
    }
    if (first * current > max)
        max = first * current;
    
    cout << max << endl;
    
    return 0;
}