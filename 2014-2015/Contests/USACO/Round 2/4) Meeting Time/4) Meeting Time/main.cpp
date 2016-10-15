#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


int N;  // number of fields
int M;  // number of paths
vector< vector< pair<int, int> > > graphBessie;
vector< vector< pair<int, int> > > graphElsie;


void input() {
    scanf("%d %d", &N, &M);
    
    graphBessie.resize(N + 1);
    graphElsie.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B, C, D;
        scanf("%d %d %d %d", &A, &B, &C, &D);
        
        graphBessie[A].push_back(make_pair(B, C));
        graphElsie[A].push_back(make_pair(B, D));
    }
}

vector<int> dijkstra(vector< vector< pair<int, int> > >& graph) {
    vector< vector<int> > dists(N + 1);
    dists[1].push_back(0);
    
    for (int vertex1 = 1; vertex1 <= N; vertex1++) {
        for (pair<int, int> edge : graph[vertex1]) {
            for (int dist : dists[vertex1])
                dists[edge.first].push_back(dist + edge.second);
        }
    }
    
    return dists[N];
}


int main() {
    freopen("meeting.in", "r", stdin);
    freopen("meeting.out", "w", stdout);
    
    input();
    
    vector<int> bessie = dijkstra(graphBessie);
    vector<int> elsie = dijkstra(graphElsie);
    sort(bessie.begin(), bessie.end());
    sort(elsie.begin(), elsie.end());
    
    for (int dist : bessie) {
        if (find(elsie.begin(), elsie.end(), dist) != elsie.end()) {
            cout << dist << endl;
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
