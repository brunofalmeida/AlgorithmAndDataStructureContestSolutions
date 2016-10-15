#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

vector< pair<int, double> > graph[501];
bool flag[501];
int apple;
bool good;

bool recurse(int node, double rate) {
	if (node == apple&&rate>1) {
		good=true;
		return true;
	}
	else {
		for (pair<int, double> edge : graph[node]) {
			if(!flag[edge.first])
			{
				flag[edge.first]=true;
				if(recurse(edge.first, rate * edge.second))
					return true;
				flag[edge.first]=false;
			}
		}
	}
	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	map<string, int> fruits;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		
		fruits[name] = i;
		
		if (name == "APPLES") {
			apple = i;
		}
	}
	
	for (int i = 0; i < M; i++) {
		string a, b;
		double c;
		
		cin >> a >> b >> c;
		
		graph[fruits[a]].push_back(pair<int, double>(fruits[b], c));
	}
	
	if(recurse(apple, 1.0))
		cout<<"YA"<<endl;
	else
		cout<<"NAW"<<endl;
	
	return 0;
}