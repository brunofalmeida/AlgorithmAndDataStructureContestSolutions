#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Input
    int N;  // number of vertices
    int M;  // number of edges
    cin >> N >> M;
    
    vector< vector<int> > graph(N + 1); // adj list
    vector<int> indegree(N + 1, 0);
    
    for (int ii = 0; ii < M; ii++) {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        indegree[j]++;
    }
    
    
    // Algorithm
    vector< map<int, long long> > paths(N + 1);  // [vertex] {path length, number of paths}
    long long total = 0;
    
    // for each vertex
    for (int v1 = 1; v1 <= N; v1++) {
        if (indegree[v1] == 0)
            paths[v1][0] = 1;
        
        // for each adjacent vertex
        for (int v2: graph[v1]) {
            
            // for each path in first vertex
            for (map<int, long long>::iterator p1 = paths[v1].begin(); p1 != paths[v1].end(); p1++) {
                if ( paths[v2].find(p1->first + 1) != paths[v2].end() )
                    paths[v2][p1->first + 1] += p1->second;
                else
                    paths[v2][p1->first + 1] = p1->second;
            }
        }
        
        if (graph[v1].size() == 0) {
            for (map<int, long long>::iterator p1 = paths[v1].begin(); p1 != paths[v1].end(); p1++)
                total += (p1->first) * (p1->second);
        }
    }
    
    
    // Output
    cout << (total % 1000000007) << endl;
    
    
    return 0;
}
