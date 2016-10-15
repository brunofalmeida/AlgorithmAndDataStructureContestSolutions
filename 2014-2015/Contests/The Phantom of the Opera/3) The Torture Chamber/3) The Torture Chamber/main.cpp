#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(long long num) {
    if (num % 2 == 0)
        return false;
    
    for (long long factor = 3; factor <= (long long)(sqrt(num)); factor += 2) {
        if (num % factor == 0)
            return false;
    }
    
    return true;
}

int main() {
    long long N, M;
    scanf("%lld", &N);
    scanf("%lld", &M);
    
    int numPrimes = 0;
    vector<bool> prime(M - N, true);
    
    if (N <= 2 and 2 < M)
        numPrimes++;

    for (long long num = max( N + (long long)(N % 2 == 0), (long long)(3) ); num < M; num += 2) {
        if (prime[num - N] and isPrime(num)) {
            numPrimes++;
        }
        else {
            prime[num - N] = false;
            for (long long mult = 2; mult < (double)(M) / num; mult++)
                prime[mult * num - N] = false;
        }
    }
    
    printf("%d\n", numPrimes);
    
    return 0;
}
