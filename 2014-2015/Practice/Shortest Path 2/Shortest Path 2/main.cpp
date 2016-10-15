#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    const int MAX = 999999999;
    
    
    int N, M;   // # of vertices, # of edges
    cin >> N >> M;
    
    vector< vector< pair<int, int> > > graph(N + 1, vector< pair<int, int> >(0));  // [vertex][list index]{vertex2, length}
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a; cin >> b; cin >> c;
        graph[a].push_back(make_pair(b, c));
    }
    
    
    vector<int> dist(N + 1, MAX);
    vector<bool> flag(N + 1, false);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        flag[v] = false;
        
        for (int i = 0; i < graph[v].size(); i++) {
            int v2 = graph[v][i].first;
            int len = graph[v][i].second;

            if (dist[v2] > dist[v] + len) {
                dist[v2] = dist[v] + len;
                if (!flag[v2]) {
                    q.push(v2);
                    flag[v2] = true;
                }
            }
        }
    }
    
    
    cout << dist[N] << endl;
    
    
    return 0;
}
