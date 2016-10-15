#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // input
    int T;  // number of types of components
    cin >> T;
    
    int N;  // number of components
    cin >> N;
    
    vector< vector<int> > costs(T + 1);     // 2D - [type][index]
    vector< vector<int> > values(T + 1);    // 2D - [type][index]
    for (int i = 0; i < N; i++)             // for each component
    {
        int c, v, t;
        cin >> c; cin >> v; cin >> t;
        costs[t].push_back(c);
        values[t].push_back(v);
    }
    
    int B;  // budget (max weight)
    cin >> B;
    
    
    // DP
    vector< vector<int> > dp( T + 1, vector<int>(B, 0) );   // 2-D - [type of component][budget]
    
    for(int t = 1; t <= T; t++)                             // for each type of component
    {
        for (int b = 1; b <= B; b++)                        // for each budget
        {
            vector<int> list;
            
            for (int i = 0; i < costs[t].size(); i++)       // for each component
            {
                int cost = costs[t][i];
                int value = values[t][i];
                
                if (  (cost <= b) and (dp[t-1][b-cost] != -1)  )
                    list.push_back( dp[t-1][b-cost] + value );
            }
            
            if (list.size() > 0)
                dp[t][b] = *max_element(list.begin(), list.end());
            else
                dp[t][b] = -1;
        }
    }
    
    
    // output
    cout << dp[T][B] << endl;
    
    
    return 0;
}
