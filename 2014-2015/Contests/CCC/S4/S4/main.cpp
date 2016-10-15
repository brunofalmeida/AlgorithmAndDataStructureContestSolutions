#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// undirected, double weighed
struct Edge {
	int b;	// to
	int t;	// time (min)
	int h;	// wear (cm)
};

// two weights
struct Path {
	int t;	// time
	int h;	// wear
};


const int MAX = 999999999;

int K;	// hull thickness (cm)
int N;	// number of islands
int M;	// number of sea routes

vector< vector<Edge> > graph;	// adjacency list - undirected, double weighted

int A;	// start
int B;	// end

vector< vector<Path> > dp;	// paths


void input() {
	scanf("%d %d %d", &K, &N, &M);
	
	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, t, h;
		scanf("%d %d %d %d", &a, &b, &t, &h);
		graph[a].push_back(Edge {b, t, h});
		graph[b].push_back(Edge {a, t, h});
	}
	
	scanf("%d %d", &A, &B);
	
	dp.resize(N + 1);
}

void spfa() {
	dp[A].push_back(Path {0, 0});
	
	vector<bool> flag(N + 1, false);
	vector<bool> flagQ(N + 1, false);
	
	queue<int> q;
	q.push(A);
	flagQ[A] = true;
	
	// for each vertex in queue
	while (q.size() > 0) {
		// get vertex
		int v1 = q.front();
		q.pop();
		flag[v1] = true;
		flagQ[v1] = false;
		
		// for each adjacent vertex
		for (int i = 0; i < graph[v1].size(); i++) {
			Edge e = graph[v1][i];
			int v2 = e.b;
			
			// if not flagged
			if (!flag[v2]) {
				// add paths
				for (int ii = 0; ii < dp[v1].size(); ii++) {
					Path p = dp[v1][ii];
					p.t += e.t;
					p.h += e.h;
					
					dp[v2].push_back(p);
				}
				
				// add v2 to queue
				if (!flagQ[v2]) {
					q.push(v2);
					flagQ[v2] = true;
				}
			}
		}
	}
}

int main() {
	//freopen("input2.txt", "r", stdin);
	
	input();
	
	spfa();
	
	int minimum = MAX;
	
	for (int i = 0; i < dp[B].size(); i++) {
		Path path = dp[B][i];
		
		if (path.h < K)
			minimum = min(minimum, path.t);
	}
	
	if (minimum == MAX)
		cout << -1 << endl;
	else
		cout << minimum << endl;
	
	return 0;
}