#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int N;	// number of buildings
map< int, vector<int> > buildings;	// [x] = {y1, y2, y3...}

int M;	// number of turning points
vector< pair<int, int> > turns;


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		buildings[x].push_back(y);
	}
	
	cin >> M;
	turns.resize(M);
	for (int i = 0; i < M; i++)
		cin >> turns[i].first >> turns[i].second;
	
	
	long long counter = 0;
	for (int i = 0; i < M - 1; i++) {
		if (turns[i].first == turns[i+1].first) {
			int x = turns[i].first;
			
			if (turns[i].second <= turns[i+1].second) {
				for (int y = turns[i].second; y <= turns[i+1].second; y++) {
					if (find(buildings[x].begin(), buildings[x].end(), y) != buildings[x].end())
						counter++;
				}
			}
			
			else {
				for (int y = turns[i].second; y >= turns[i+1].second; y--) {
					if (find(buildings[x].begin(), buildings[x].end(), y) != buildings[x].end())
						counter++;
				}
			}
			
		}
		
		else {
			int y = turns[i].second;
			
			if (turns[i].first <= turns[i+1].first) {
				for (int x = turns[i].first; x <= turns[i+1].first; x++) {
					if (find(buildings[x].begin(), buildings[x].end(), y) != buildings[x].end())
						counter++;
				}
			}
			
			else {
				for (int x = turns[i].first; x >= turns[i+1].first; x--) {
					if (find(buildings[x].begin(), buildings[x].end(), y) != buildings[x].end())
						counter++;
				}
			}
		}
	}
	
	
	cout << counter << endl;
	
	
    return 0;
}
