#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // input
    int x;  // money
    cin >> x;
    int n;  // number of denominations
    cin >> n;
    vector<int> denoms(n);
    for (int i = 0; i < n; i++)
        cin >> denoms[i];
    
    
    // DP
    vector<int> dp(x + 1, 999999);
    dp[0] = 0;
    for (int change = 0; change <= x; change++) // for each amount of change
    {
        for (int i = 0; i < denoms.size(); i++) // for each coin denomination
        {
            if (  (denoms[i] <= change) and ( dp[change - denoms[i]] + 1 < dp[change] )  )
                dp[change] = dp[change - denoms[i]] + 1;
        }
    }
    
    
    // output
    cout << dp[x] << endl;
    
    
    return 0;
}
