#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num % 2 == 0)
        return false;
    
    for (int factor = 3; factor <= (int)(sqrt(num)); factor += 2) {
        if (num % factor == 0)
            return false;
    }
    
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        int counter = 0;
        
        if (a <= 2 and 2 < b)
            counter++;
        
        if (a == 1)
            a = 3;
        for (int num = a + (int)(a % 2 == 0); num < b; num += 2) {
            if (isPrime(num))
                counter++;
        }
        
        cout << counter << endl;
    }
    
    return 0;
}
