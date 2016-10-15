#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int n;	// number of pieces
	cin >> n;
	
	int k;	// number of people
	cin >> k;
	
	
	// [number of people] { (last person, total), ... }
	vector< vector< pair<int, int> > > dp(k + 1);
	dp[0].push_back(make_pair(1, 0));
	
	for (int personNum = 1; personNum <= k; personNum++) {
		for (pair<int, int> state : dp[personNum - 1]) {
			for (int personAmount = state.first; personAmount <= ((n - state.second) / (k - personNum + 1)); personAmount++)
				dp[personNum].push_back(make_pair(personAmount, state.second + personAmount));
		}
	}
	
	
	int counter = 0;
	for (pair<int, int> state : dp[k]) {
		if (state.second == n)
			counter++;
	}
	cout << counter << endl;
	
	
    return 0;
}
