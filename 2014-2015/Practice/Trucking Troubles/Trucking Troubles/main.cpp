#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


#define MAX 999999

int c;  // number of cities
int r;  // number of roads
int d;  // number of destination cities

vector< vector< pair<int, int> > > graph;
vector<int> destinations;


void input() {
    scanf("%d", &c); scanf("%d", &r); scanf("%d", &d);
    
    graph.resize(c + 1);
    for (int i = 0; i < r; i++) {
        int x, y, w;
        scanf("%d", &x); scanf("%d", &y); scanf("%d", &w);
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }
    
    destinations.resize(d);
    for (int i = 0; i < d; i++)
        scanf("%d", &destinations[i]);
}

int getVertex(vector<int>& dp, vector<bool>& flag) {
    int vertex = 1;
    int maximum = 0;
    
    for (int v = 2; v <= c; v++) {
        if (dp[v] > maximum and !flag[v]) {
            vertex = v;
            maximum = dp[v];
        }
    }
    
    return vertex;
}

int mst() {
    int minimum = MAX;
    int numDestinations = 0;    // number of destinations connected
    
    vector<int> dp(c + 1, -1);
    dp[1] = 0;
    
    vector<bool> flag(c + 1, false);
    flag[1] = true;
    
    while (numDestinations < d) {
        int vertex1 = getVertex(dp, flag);
        flag[vertex1] = true;
        if (find(destinations.begin(), destinations.end(), vertex1) != destinations.end())
            numDestinations++;
        if (dp[vertex1] < minimum and vertex1 != 1)
            minimum = dp[vertex1];
        
        for (pair<int, int> edge : graph[vertex1]) {
            if (!flag[edge.first])
                dp[edge.first] = max(dp[edge.first], edge.second);
        }
    }
    
    return minimum;
}


int main() {
    // freopen("in.txt", "r", stdin);
    
    input();
    
    cout << mst() << endl;
    
    return 0;
}
