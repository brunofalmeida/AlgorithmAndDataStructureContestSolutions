#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r,c,sx,sy,x,y,dp[120][700][700];
char grid[120][700];
bool flag[120][700][700],possible[120][700][700];    // row column wait
struct info {
	int r,c,w;
};

queue <info> q;

int main() {
	freopen("DATA32.txt", "r", stdin);
	
	////////////////////////////////////////////////////////////////////////
	for (int testCase = 0; testCase < 10; testCase++) {
		for (int i = 0;i<=r+1;i++)
			for (int j = 0;j<=c;j++)
				for (int k = 0;k<c;k++)
					possible[i][j][k] = 0;
		
		scanf("%d%d",&r,&c);
		
		for (int i = 1;i<=r;i++)
			for (int j = 1;j<=c;j++) {
				cin >> grid[i][j];
				if (grid[i][j] != '*')
					possible[i][j][0] = 1;
			}
		
		for (int i = 0;i<=c;i++) {
			for (int j= 0;j<c;j++)
			possible[0][i][j] = possible[r+1][i][j] = 1;
		}
		
		for (int t = 1;t<c;t++) {
			bool a = 1; // 1 for left, 0 for right
			
			for (int i = r+1;i>=0;i--) {
				a = 1 - a;
				
				for (int j = 0;j<=c;j++) {
					if (a == 1) {
						int cool = j+1;
						if (cool > c) cool -= c;
						if (!possible[i][cool][t-1])
							possible[i][j][t] = 0;
						else possible[i][j][t] = 1;
					} else {
						int cool = j - 1;
						if (cool <= 0) cool += c;
						if (!possible[i][cool][t-1])
							possible[i][j][t] = 0;
						else possible[i][j][t] = 1;
					}
				}
			}
		}
		
		/*
		for (int t = 0;t<c;t++) {
			for (int i = 0;i<=r+1;i++) {
				for (int j = 0;j<=c;j++)
					cout << possible[i][j][t] << " " ;
				cout << endl;
			}
			cout << endl;
		}
		 */
		
		for (int i = 0;i<=r+1;i++)for (int j = 0;j<=c;j++) for (int k = 0;k<c;k++) dp[i][j][k] = 99999;
		
		sx = r + 1;
		sy = c/2 + 1;
		dp[sx][sy][0] = 0;
		q.push({sx,sy,0});
		
		while (!q.empty()) {
			int x = q.front().r; // row
			int y = q.front().c; // column
			int s = q.front().w; // wait
			q.pop();
			
			//cout << x<< " " << y << " " << s << endl;
			
			if (x > 0) {
				if (possible[x-1][y][(s+1)%c] && dp[x-1][y][(s+1)%c] > dp[x][y][s]+1) {
					dp[x-1][y][(s+1)%c] = dp[x][y][s] + 1;
					q.push({x-1,y,(s+1)%c});
				}
				
				// cout << x << " " << y << " " << (s+1)%c << endl;
				// cout << possible[x][y][(s+1)%c] << endl;
				// cout << dp[x][y][s] << " " << dp[x][y][(s+1)%c] << endl;
				
				if (possible[x][y][(s+1)%c] && dp[x][y][(s+1)%c] > dp[x][y][s]+1) {
					dp[x][y][(s+1)%c] = dp[x][y][s] + 1;
					q.push({x,y,(s+1)%c});
				}
			}
		}
		
		int ans = 1e9;
		for (int t = 0;t<c;t++) {
			ans = min(ans,dp[0][sy][t]);
		}
		
		if (ans == 99999) cout << "Not Possible" << endl;
		else cout << ans << endl;
	}
}
