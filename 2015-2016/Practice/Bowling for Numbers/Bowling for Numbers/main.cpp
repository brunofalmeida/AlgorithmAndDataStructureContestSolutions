#include <iostream>

using namespace std;


int t;  // number of test cases

int n;  // number of bowling pins
int k;  // number of bowling balls available
int w;  // width of bowling ball

int pins[30000];    // scores of pins

int dp[501][30000];    // [number of bowling balls][pin end number]


int main() {
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &n, &k, &w);
        
        for (int i2 = 0; i2 < n; i2++) {
            scanf("%d", &pins[i2]);
        }
        
        
    }
    
    return 0;
}
