#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // input
    int R, C;
    cin >> R; cin >> C;
    
    int K;
    cin >> K;
    vector< vector<bool> > cats( C, vector<bool> (R, false) );  // 2d grid - C x R
    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r; cin >> c;
        cats[c - 1][r - 1] = true;
    }
    
    
    // DP
    vector< vector<int> > dp( C, vector<int> (R, 0) );  // 2d grid - C x R
    dp[0][0] = 1;
    
    for (int x = 1; x < C; x++) // top row
    {
        if (! cats[x][0])
            dp[x][0] = dp[x - 1][0];
    }
    
    for (int y = 1; y < R; y++) // left column
    {
        if (! cats[0][y])
            dp[0][y] = dp[0][y - 1];
    }
    
    for (int x = 1; x < C; x++)
    {
        for (int y = 1; y < R; y++)
        {
            if (! cats[x][y])
                dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
        }
    }
    
    
    // output
    cout << dp[C - 1][R - 1] << endl;
    
    
    return 0;
}
