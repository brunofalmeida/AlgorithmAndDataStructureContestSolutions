#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


struct Edge {
    int from;
    int to;
    int cost;
};


const int MAX = 999999;

int N;  // number of animals/pens
vector<Edge> graph; // edges - 0 is outside


void updateGraph(vector< vector< pair<int, int> > >& cornerGraph, int pen, int c1, int c2, int cost) {
    if (cornerGraph[c1][c2].first == -1) {
        cornerGraph[c1][c2] = make_pair(pen, cost);
        cornerGraph[c2][c1] = make_pair(pen, cost);
    }
    else {
        graph.push_back(Edge{pen, cornerGraph[c1][c2].first, cost});
        cornerGraph[c1][c2] = make_pair(-1, 0);
        cornerGraph[c2][c1] = make_pair(-1, 0);
    }
}

void input() {
    cin >> N;
    
    // [corner 1][corner 2] {pen number, cost}
    vector< vector< pair<int, int> > > cornerGraph(1001, vector< pair<int, int> > (1001, pair<int, int> (-1, 0)));
    
    for (int pen = 1; pen <= N; pen++) {  // for each pen
        int e;  // number of edges around pen
        cin >> e;
        
        vector<int> corners(e);
        for (int i = 0; i < e; i++)
            cin >> corners[i];
        
        vector<int> costs(e);
        for (int i = 0; i < e; i++)
            cin >> costs[i];
        
        for (int i = 0; i < e - 1; i++)
            updateGraph(cornerGraph, pen, corners[i], corners[i + 1], costs[i]);
        updateGraph(cornerGraph, pen, corners[0], corners[e - 1], costs[e - 1]);
    }
    
    for (int c1 = 0; c1 < 1001; c1++) {
        for (int c2 = 0; c2 < 1001; c2++) {
            if (cornerGraph[c1][c2].first != -1) {
                graph.push_back(Edge{0, cornerGraph[c1][c2].first, cornerGraph[c1][c2].second});
                cornerGraph[c1][c2] = make_pair(-1, 0);
                cornerGraph[c2][c1] = make_pair(-1, 0);
            }
        }
    }
}

Edge getEdge(vector<bool>& flag) {
    int index = 0;
    int min = MAX;
    
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].cost < min) {
            Edge edge = graph[i];
            if ( (flag[edge.from] and !flag[edge.to]) or (!flag[edge.from] and flag[edge.to]) ) {
                index = i;
                min = edge.cost;
            }
        }
    }
    
    Edge edge = graph[index];
    graph.erase(graph.begin() + index);
    return edge;
}

int prim(int numVertices) {
    int total = 0;
    
    vector<bool> flag(N + 1, false);
    flag[1] = true;
    
    for (int i = 0; i < numVertices - 1; i++) {
        Edge edge = getEdge(flag);
        flag[edge.from] = true;
        flag[edge.to] = true;
        total += edge.cost;
    }
    
    return total;
}


int main() {
    // freopen("in.txt", "r", stdin);
    
    input();
    
    
    vector<Edge> graphOld(graph);
    
    int answer = prim(N + 1);
    
    graph = graphOld;
    for (int i = graph.size() - 1; i >= 0; i--) {
        if (graph[i].from == 0 or graph[i].to == 0)
            graph.erase(graph.begin() + i);
    }
    
    answer = min(answer, prim(N));
    
    
    cout << answer << endl;
    
    
    return 0;
}
