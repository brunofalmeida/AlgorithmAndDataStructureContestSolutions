#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> array(N);
    for (int i = 0; i < N; i++)
        cin >> array[i];
    
    vector< pair<bool, int> > dp(N);    // uses current number, sum
    dp[0] = make_pair(true, array[0]);
    dp[1] = make_pair(true, array[1]);
    
    for (int i = 2; i < N; i++) {
        dp[i] = make_pair(false, dp[i - 1].second);
        
        if (dp[i].second < dp[i - 2].second + array[i])
            dp[i] = make_pair(true, dp[i - 2].second + array[i]);
    }
    
    cout << dp[N - 1].second << endl;
    
    return 0;
}
