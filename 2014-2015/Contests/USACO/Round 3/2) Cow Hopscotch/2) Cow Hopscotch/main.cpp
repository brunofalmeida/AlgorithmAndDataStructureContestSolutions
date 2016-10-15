#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	
	int R, C;	// grid dimensions
	int K;		// integer range
	cin >> R >> C >> K;
	
	vector< vector<int> > grid(R, vector<int>(C));
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++)
			cin >> grid[r][c];
	}
	
	
	vector< vector<long long> > dp(R, vector<long long>(C, 0));
	dp[0][0] = 1;
	
	for (int r1 = 0; r1 < R; r1++) {
		for (int c1 = 0; c1 < C; c1++) {
			
			for (int r2 = r1 + 1; r2 < R; r2++) {
				for (int c2 = c1 + 1; c2 < C; c2++) {
					
					if (grid[r1][c1] != grid[r2][c2])
						dp[r2][c2] += dp[r1][c1];
				}
			}
		}
	}
	
	
	cout << (dp[R - 1][C - 1]) % 1000000007 << endl;

	
    return 0;
}
