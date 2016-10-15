#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // Input
    int N; cin >> N;    // # of vertices
    
    int graph[N + 1][N + 1];
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++)
            cin >> graph[y][x];
    }
    
    
    // BFS
    vector< vector<int> > connectedComponents;
    vector<bool> flag(N + 1, false);
    
    for (int v = 1; v <= N; v++) {
        if (!flag[v]) {
            vector<int> cc;
            queue<int> q;
            
            q.push(v);
            flag[v] = true;
            
            while (q.size() > 0) {
                int vertex = q.front();
                q.pop();
                
                cc.push_back(vertex);
                
                for (int vertex2 = 1; vertex2 <= N; vertex2++) {
                    if (graph[vertex][vertex2] and !flag[vertex2] and vertex != vertex2) {
                        q.push(vertex2);
                        flag[vertex2] = true;
                    }
                }
            }
            
            sort(cc.begin(), cc.end());
            connectedComponents.push_back(cc);
        }
    }
    
    
    // Output
    for (int i = 0; i < connectedComponents.size(); i++) {
        for (int ii = 0; ii < connectedComponents[i].size() - 1; ii++)
            cout << connectedComponents[i][ii] << " ";
        cout << connectedComponents[i][connectedComponents[i].size() - 1] << endl;
    }
    
    
    return 0;
}
