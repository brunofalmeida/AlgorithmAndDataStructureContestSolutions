#include <iostream>
#include <vector>

using namespace std;

int main() {
	//freopen("paprika.dummy.in.3", "r", stdin);
	
	int N;	// number of peppers
	int X;	// age limit for stuffing
	cin >> N >> X;
	
	vector< pair<int, int> > peppers(N);	// age, life purpose (0-fresh, 1-stuffed)
	for (int i = 0; i < N; i++)
		cin >> peppers[i].first >> peppers[i].second;
	
	
	int counter = 0;
	for (int i = 0; i < N - 1; i++) {
		if (peppers[i].first > peppers[i+1].first and peppers[i].second == 1 and peppers[i+1].second == 0) {
			int iTemp = peppers[i].first;
			peppers[i].first = peppers[i+1].first;
			peppers[i+1].first = iTemp;
		}
		else if (peppers[i].first < peppers[i+1].first and peppers[i].second == 0 and peppers[i+1].second == 1) {
			int iTemp = peppers[i].first;
			peppers[i].first = peppers[i+1].first;
			peppers[i+1].first = iTemp;
		}
		
		if (peppers[i].first <= X and peppers[i].second == 1)
			counter++;
		else if (peppers[i].first > X and peppers[i].second == 0)
			counter++;
	}
	
	if (peppers[N-1].first <= X and peppers[N-1].second == 1)
		counter++;
	else if (peppers[N-1].first > X and peppers[N-1].second == 0)
		counter++;
	
	
	cout << counter << endl;
	
	
    return 0;
}
