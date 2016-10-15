#include <iostream>

using namespace std;

int main() {
    long long N;
    cin >> N;
    
    long long sum = 1;
    
    for (long long i = 2; i < N; i++) {
        sum = sum | i;
    }
    
    sum = sum | N;
    
    
    for (int i = 2e33; i >= 1; i /= 2) {
        if ((sum & i) > 0) {
            for (int base = i; base >= 1; base /= 2) {
                if ((sum & base) > 0) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
        }
    }
    
    if (sum == 0) {
        cout << 0;
    }
    cout << endl;
    
    return 0;
}
