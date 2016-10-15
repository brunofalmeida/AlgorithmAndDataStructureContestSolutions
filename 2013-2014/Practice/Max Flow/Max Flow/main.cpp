#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int T, N;
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int flows [N];
        for (int ii = 0; ii < N; ii++)
            cin >> flows [ii];
        sort (flows, flows + N);
        cout << flows [N - 1] << endl;
    }
    return 0;
}