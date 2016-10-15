#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // input
    int distance;
    cin >> distance;
    int numClubs;
    cin >> numClubs;
    
    vector<int> clubs(numClubs);
    for (int i = 0; i < numClubs; i++)
        cin >> clubs[i];
    
    
    // DP
    vector<int> dp(distance + 1, 99);
    dp[0] = 0;
    for (int d = 1; d <= distance; d++) // for each distance
    {
        for (int i = 0; i < numClubs; i++)  // for each club index
        {
            int c = clubs[i];   // club value
            
            if ( c <= d and dp[d - c] + 1 < dp[d] )
                dp[d] = dp[d - c] + 1;
        }
    }
    
    
    // output
    if (dp[distance] != 99)
        cout << "Roberta wins in " << dp[distance] << " strokes." << endl;
    else
        cout << "Roberta acknowledges defeat." << endl;
    
    
    return 0;
}
