#include <iostream>
#include <algorithm>

using namespace std;

int N;              // number of coins
int coins[1000];    // values of coins
int dp[1000];       // max score

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    
    
    dp[0] = coins[0];
    
    for (int i = 1; i < N; i++) {
        dp[i] = max(dp[0], dp[i - 1]);
    }
    
    
    return 0;
}
