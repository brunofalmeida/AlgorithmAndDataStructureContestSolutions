#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 999;
    
    
    int H;  // target height
    cin >> H;
    
    int S;  // number of blocks
    cin >> S;
    
    vector<int> blocks(S);
    for (int i = 0; i < S; i++)
        cin >> blocks[i];
    
    
    vector< vector<int> > dp(S + 1, vector<int>(H + 1, MAX)); // 2D - [number of blocks][height] = number used
    for (int i = 0; i <= S; i++)    // no-height values = 0
        dp[i][0] = 0;
    
    for (int n = 1; n <= S; n++) {      // for each number of blocks
        for (int h = 1; h <= H; h++) {  // for each height
            dp[n][h] = min( dp[n-1][h], dp[n-1][h-blocks[n-1]] + 1 );
        }
    }
    
    
    if (dp[S][H] != MAX)
        cout << dp[S][H] << endl;
    else
        cout << 0 << endl;
    
    
    return 0;
}
