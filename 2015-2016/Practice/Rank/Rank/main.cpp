#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;  // number of players
    int K;  // number of games
    cin >> N >> K;
    
    vector< vector<int> > graph(N + 1);
    
    for (int i = 0; i < K; i++) {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        
        if (sa > sb) {
            graph[a].push_back(b);
        } else {
            graph[b].push_back(a);
        }
    }
    
    int numImpossible = 0;
    
    for (int i = 1; i <= N; i++) {
        stack<int> s;
        vector<bool> flag(N + 1, false);
        
        s.push(i);
        flag[i] = true;
        
        while (s.size() > 0) {
            int player = s.top();
            s.pop();
            
            bool done = false;
            
            for (int nextPlayer : graph[player]) {
                
                if (nextPlayer == i) {
                    numImpossible++;
                    done = true;
                    
                } else if (flag[nextPlayer] == false) {
                    s.push(nextPlayer);
                    flag[nextPlayer] = true;
                }
            }
            
            if (done) {
                break;
            }
        }
    }
    
    cout << numImpossible << endl;
    
    return 0;
}
