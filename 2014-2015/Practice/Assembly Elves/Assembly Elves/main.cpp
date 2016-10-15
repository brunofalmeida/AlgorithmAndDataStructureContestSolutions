#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 999999;

int main() {
    int X;      // type of toy
    cin >> X;
    
    vector< set<int> > dp(101);
    dp[1].insert(1);
    
    for (int x = 2; x <= X; x++) {  // for each kind of toy
        int minLength = MAX;
        set<int> minUnits;
        
        for (int a = x / 2, b = x - a; 1 <= a and b < x; a--, b++) {
            set<int> units;
            units.insert(dp[a].begin(), dp[a].end());
            units.insert(dp[b].begin(), dp[b].end());
            
            if (minLength > units.size()) {
                minLength = units.size();
                minUnits = units;
            }
        }
        
        dp[x] = minUnits;
        dp[x].insert(x);
    }
    
    cout << dp[X].size() << endl;
    set<int>::iterator it = dp[X].begin();
    cout << *it++;
    for (; it != dp[X].end(); it++)
        cout << " " << *it;
    cout << endl;
    
    return 0;
}
