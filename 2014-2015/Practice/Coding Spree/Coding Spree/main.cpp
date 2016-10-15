#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;   // # of problems, # of hours
    cin >> N; cin >> T;
    
    vector<int> values(N);
    vector<int> hours(N);
    for (int i = 0; i < N; i++) {
        cin >> values[i]; cin >> hours[i];
    }
    
    
    vector< vector<int> > dp( N + 1, vector<int>(T + 1, 0) );
    
    for (int n = 1; n <= N; n++) {
        for (int t = 1; t <= T; t++) {
            if (hours[n-1] <= t)
                dp[n][t] = max( dp[n-1][t], dp[n-1][t - hours[n-1]] + values[n-1] );
            else
                dp[n][t] = dp[n-1][t];
        }
    }
    
    
    cout << dp[N][T] << endl;
    
    
    return 0;
}
