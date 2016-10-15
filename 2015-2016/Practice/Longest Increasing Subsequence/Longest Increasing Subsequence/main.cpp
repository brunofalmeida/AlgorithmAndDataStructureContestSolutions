#include <iostream>

using namespace std;

int nums[5000];
int dp[5000];   // longest sequence up to and including current index

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    // For each index
    for (int i = 0; i < N; i++) {
        
        // Default sequence of just the current number
        dp[i] = 1;
        
        // For each previous index
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    // Output max length
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    cout << max << endl;
    
    return 0;
}
