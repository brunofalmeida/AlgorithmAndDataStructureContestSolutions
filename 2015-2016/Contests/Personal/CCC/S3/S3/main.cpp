#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <cstring>

#define MAX_NM 100000
#define INFINITY 999999999
//#define LOG

using namespace std;

int N;  // number of restaurants
int M;  // number of pho restaurants
bool pho[MAX_NM];           // true if pho restaurant
vector<int> graph[MAX_NM];  // adjacency list

// answer
int minTime = INFINITY;

// for DFS
bool visited[MAX_NM];

// return time taken to explore paths starting at this node, time that can be subtracted if we don't have to return
pair<int, int> DFS(int n) {
#ifdef LOG
    cout << "visiting " << n << endl;
#endif
    
    visited[n] = true;
    
    vector<pair<int, int>> pathTimes;
    
    for (int nNext : graph[n]) {
        if (! visited[nNext]) {
            pair<int, int> p = DFS(nNext);
            
            if (p.first > -1) {
                p.first  += 2;
                p.second += 1;
                pathTimes.push_back(p);
                
#ifdef LOG
                cout << "adding path " << p.first << ", " << p.second << " for node " << n << endl;
#endif
            }
        }
    }
    
    if (pathTimes.size() > 0) {
        int time = 0;
        vector<int> reductions;
        
        for (pair<int, int> p : pathTimes) {
            time += p.first;
            reductions.push_back(p.second);
        }
        
        sort(reductions.begin(), reductions.end());
        
#ifdef LOG
        cout << "for node " << n << endl;
        cout << "time: " << time << endl;
        cout << "reductions: ";
        for (int reduction : reductions) {
            cout << reduction << ", ";
        }
        cout << endl;
#endif
        
        return make_pair(time, reductions[reductions.size() - 1]);
        
    } else if (pho[n]) {
        return make_pair(0, 0);
    } else {
        return make_pair(-1, 0);
    }
}


int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int m;
        cin >> m;
        pho[m] = true;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    
    for (int n = 0; n < N; n++) {
#ifdef LOG
        cout << endl << "starting at " << n << endl;
#endif
        
        if (n > 0) {
            memset(visited, false, sizeof(visited));
        }
        
        pair<int, int> p = DFS(n);
        
        int curTime = p.first - p.second;
        if (curTime < minTime) {
            minTime = curTime;
        }
        
#ifdef LOG
        cout << "for node " << n << endl;
        cout << "curtime: " << curTime << endl << "mintime: " << minTime << endl;
#endif
    }
    
    
    cout << minTime << endl;
    
    
    return 0;
}

