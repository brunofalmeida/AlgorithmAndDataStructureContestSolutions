#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Edge {
    int end;    // end
    int flow;   // flow
    int super;  // superpower
};

bool canCalculate(int node, const vector< vector<Edge> >& graph, vector<double>& dp) {
    for (int i = 0; i < graph[node].size(); i++) {
        if (dp[graph[node][i].end] == -1)
            return false;
    }
    
    return true;
}

void calculate(int node, const vector< vector<Edge> >& graph, vector<double>& dp) {
    double min = 0;
    
    for (int i = 0; i < graph[node].size(); i++) {
        Edge edge = graph[node][i];
        int node2 = edge.end;
        
        if (!edge.super)    // normal pipe
            min = max( min, dp[node2] / (edge.flow / 100.0) );
        else                // super pipe
            min = max( min, sqrt(dp[node2]) / (edge.flow / 100.0) );
    }
    
    dp[node] = min;
}

int main() {
    // File
    // freopen("mravi.dummy.in.3", "r", stdin);
    
    
    // Input
    int N; cin >> N;    // number of nodes
    
    vector< vector<Edge> > graph(N + 1, vector<Edge>(0));   // adjacency list
    for (int i = 0; i < N - 1; i++) {
        int A, B, X, T; // start, end, flow, superpower
        cin >> A; cin >> B; cin >> X; cin >> T;
        graph[A].push_back(Edge{B, X, T});
    }
    
    vector<double> dp(N + 1);   // water needed for node
    for (int i = 1; i <= N; i++)
        cin >> dp[i];
    
    
    // Algorithm
    bool repeat;
    do {
        repeat = false;
        
        for (int n = 1; n <= N; n++) {
            if (dp[n] == -1 and canCalculate(n, graph, dp)) {
                calculate(n, graph, dp);
                repeat = true;
            }
        }
    } while (repeat);
    
    
    // Output
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << dp[1] << endl;
    
    
    return 0;
}
