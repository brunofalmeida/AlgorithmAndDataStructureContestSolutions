#include <iostream>
#include <vector>

using namespace std;


int main()
{
    // input
    int n;
    cin >> n;
    
    
    for (int i = 0; i < n; i++) // for each test case
    {
        // test case input
        int A, B, C, D;
        cin >> A; cin >> B; cin >> C; cin >> D;
        
        vector<   vector<  vector< vector<bool> >  >   > dp;  // 4-D vector <bool> - True if winning position
        
        dp.resize(A + 1);
        for (int a = 0; a <= A; a++)
        {
            dp[a].resize(B + 1);
            for (int b = 0; b <= B; b++)
            {
                dp[a][b].resize(C + 1);
                for (int c = 0; c <= C; c++)
                {
                    dp[a][b][c].resize(D + 1);
                    for (int d = 0; d <= D; d++)
                        dp[a][b][c][d] = false;
                }
            }
        }
    
        
        // DP
        vector< vector<int> > reactions = {
                                            {2, 1, 0, 2},
                                            {1, 1, 1, 1},
                                            {0, 0, 2, 1},
                                            {0, 3, 0, 0},
                                            {1, 0, 0, 1}
                                          };
        
        for (int a = 0; a <= A; a++)
        {
            for (int b = 0; b <= B; b++)
            {
                for (int c = 0; c <= C; c++)
                {
                    for (int d = 0; d <= D; d++)
                    {
                        for (int i = 0; i < 5; i++) // for each reaction
                        {
                            // if player can make the reaction and the next reaction will be a losing reaction, it is winning
                            if (
                                a >= reactions[i][0] and b >= reactions[i][1] and c >= reactions[i][2] and d >= reactions[i][3] and
                                dp[a - reactions[i][0]][b - reactions[i][1]][c - reactions[i][2]][d - reactions[i][3]] == false
                                )
                                dp[a][b][c][d] = true;
                        }
                    }
                }
            }
        }
        
        
        // output
        if (dp[A][B][C][D])
            cout << "Patrick" << endl;
        else
            cout << "Roland" << endl;
    }
    
    
    return 0;
}
