#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


const int MAX = 999999999;

int N;  // number of cities
int T;  // number of trade routes
vector< vector< pair<int, int> > > graph;   // city, shipping cost

int K;  // number of cities with pencil stores
vector< pair<int, int> > pencils;           // city, purchase cost

int D;  // destination city


void input() {
    cin >> N;
    cin >> T;
    graph.resize(N + 1);
    
    for (int i = 0; i < T; i++) {
        int x, y, C;
        cin >> x >> y >> C;
        graph[x].push_back(make_pair(y, C));
        graph[y].push_back(make_pair(x, C));
    }
    
    cin >> K;
    pencils.resize(K);
    
    for (int i = 0; i < K; i++) {
        int z, P;
        cin >> z >> P;
        pencils[i] = make_pair(z, P);
    }
    
    cin >> D;
}

// return node with minimum cost
int getNode(const vector<int>& cost, const vector<bool>& flag) {
    int node = 0;
    int min = MAX;
    
    for (int i = 1; i <= N; i++) {
        if ( (!flag[i]) and (min > cost[i]) ) {
            node = i;
            min = cost[i];
        }
    }
    
    return node;
}

// return shipping cost
int dijk() {
    vector<int> cost(N + 1, MAX);
    cost[D] = 0;
    
    vector<bool> flag(N + 1, false);
    
    for (int i = 0; i < N; i++) {
        int node1 = getNode(cost, flag);
        flag[node1] = true;
        
        for (pair<int, int> edge : graph[node1]) {
            int node2 = edge.first;
            int edgeCost = edge.second;
            
            if (!flag[node2])
                cost[node2] = min(cost[node2], cost[node1] + edgeCost);
        }
    }
    
    int minimum = MAX;
    for (pair<int, int> pencil : pencils)
        minimum = min(minimum, cost[pencil.first] + pencil.second);
    return minimum;
}


int main() {
    cout.sync_with_stdio(false);
    
    input();
    
    cout << dijk() << endl;
    
    return 0;
}
