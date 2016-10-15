#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX = 999999;

int getMinVertex(const vector<int>& dijk, const vector<bool>& flag) {
    int vertex = 1;
    int min = MAX;
    
    for (int i = 1; i < flag.size(); i++) {
        if (!flag[i] and dijk[i] < min) {
            vertex = i;
            min = dijk[i];
        }
    }
    
    return vertex;
}

int main() {
    // Input
    int N;  // number of computers
    int W;  // number of wires
    int P;  // number of packets
    cin >> N >> W >> P;
    
    vector< vector< pair <int, int> > > graph(N + 1); // adjacency list - {computer, time}
    for (int i = 0; i < W; i++) {
        int comp1, comp2, time;
        cin >> comp1 >> comp2 >> time;
        
        graph[comp1].push_back(make_pair(comp2, time));
        graph[comp2].push_back(make_pair(comp1, time));
    }
    
    
    // Test case
    for (int p = 0; p < P; p++) {
        // Input
        int source, destination;
        cin >> source >> destination;
        
        
        // Dijkstra's
        vector<int> dijk(N + 1, MAX);       // distance from source
        dijk[source] = 0;
        
        vector<bool> flag(N + 1, false);    // known distances
        
        for (int i = 0; i < N; i++) {       // for each vertex
            int vertex1 = getMinVertex(dijk, flag);
            flag[vertex1] = true;
            
            for (pair<int, int> edge : graph[vertex1]) {    // for each adjacent vertex
                int vertex2 = edge.first;
                int distance = edge.second;
                
                if (!flag[vertex2])
                    dijk[vertex2] = min(dijk[vertex2], dijk[vertex1] + distance);
            }
        }
        
        
        // Output
        cout << dijk[destination] << endl;
    }
    
    
    return 0;
}
