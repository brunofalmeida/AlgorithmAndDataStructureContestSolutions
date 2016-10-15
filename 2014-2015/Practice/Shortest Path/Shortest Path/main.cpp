#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector< vector<bool> > graph( N, vector<bool>(N) );
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int n; cin >> n;
            if (n == 0)
                graph[y][x] = false;
            else
                graph[y][x] = true;
        }
    }
    
    
    vector<int> BFS(N, -1);
    queue<int> q;
    
    BFS[0] = 0;
    q.push(0);
    
    while (q.size() > 0) {
        int vertex = q.front();
        q.pop();
        
        if (vertex == N - 1)
            break;
        
        for (int v2 = 0; v2 < N; v2++) {
            if (graph[vertex][v2] and BFS[v2] == -1) {
                BFS[v2] = BFS[vertex] + 1;
                q.push(v2);
            }
        }
    }
    
    
    cout << BFS[N-1] << endl;
    
    
    return 0;
}
