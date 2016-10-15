#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

#define INF 999999

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector< vector<int> > graphOld(N, vector<int>(N));
    
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> graphOld[row][col];
        }
    }
    
    int minNumToRemove = INF;
    
    for (int i = 0; i < N; i++) {
        int numToRemove = 0;
        
        vector< vector<int> > graph(graphOld);
        vector<int> dist(N, INF);
        queue< pair<int, int> > q;  // node, parent node
        
        dist[i] = 0;
        q.push(make_pair(i, i));
        
        while (q.size() > 0) {
            pair<int, int> curr = q.front();
            int node = curr.first;
            int parent = curr.second;
            q.pop();
            
            for (int nodeTwo = 0; nodeTwo < N; nodeTwo++) {
                if (graph[node][nodeTwo] == 1 && nodeTwo != parent) {
                    
                    if (dist[nodeTwo] <= dist[node]) {
                        numToRemove++;
                        graph[node][nodeTwo] = 0;
                        graph[nodeTwo][node] = 0;
                        
                    } else if (dist[nodeTwo] == INF) {
                        dist[nodeTwo] = dist[node] + 1;
                        q.push(make_pair(nodeTwo, node));
                    }
                }
            }
        }
        
        minNumToRemove = min(minNumToRemove, numToRemove);
    }
    
    cout << minNumToRemove << endl;
    
    return 0;
}
