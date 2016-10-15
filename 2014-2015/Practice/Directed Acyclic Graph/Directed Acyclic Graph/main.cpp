#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector< vector<int> > graph(N, vector<int> (N));
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++)
            cin >> graph[y][x];
    }
    
    bool isCyclic = false;
    
    for (int vertex = 0; vertex < N; vertex++) {
        vector<bool> flag(N, false);
        vector<bool> flagQ(N, false);
        
        queue<int> q;
        
        for (int vertex2 = 0; vertex2 < N; vertex2++) {
            if (graph[vertex][vertex2] == 1) {
                q.push(vertex2);
                flagQ[vertex2] = true;
            }
        }
        
        while (q.size() > 0) {
            int v1 = q.front();
            q.pop();
            flag[v1] = true;
            flagQ[v1] = false;
            
            if (v1 == vertex) {
                isCyclic = true;
                break;
            }
            
            for (int v2 = 0; v2 < N; v2++) {
                if (graph[v1][v2] == 1 and !flag[v2] and !flagQ[v2]) {
                    q.push(v2);
                    flagQ[v2] = true;
                }
            }
        }
        
        if (isCyclic)
            break;
        
    }
    
    if (isCyclic)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    
    return 0;
}
