#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	
	for (int i = 0; i < 5; i++) {
		int height, width;
		cin >> width;
		cin >> height;
		
		vector< vector<bool> > grid(height, vector<bool>(width));
		
		for (int y = 0; y < height; y++) {
			string row;
			cin >> row;
			
			for (int x = 0; x < width; x++) {
				if (row[x] == 'X')
					grid[y][x] = true;
				else
					grid[y][x] = false;
			}
		}
		
		
		vector< vector<bool> > flag(height, vector<bool>(width, false));
		int numShapes = 0;
		
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (grid[y][x] and !flag[y][x]) {
					numShapes++;
					
					stack< pair<int, int> > s;
					s.push(pair<int, int>(y, x));
					flag[y][x] = true;
					
					while (s.size() > 0) {
						int yPos = s.top().first;
						int xPos = s.top().second;
						s.pop();
						
						vector< pair<int, int> > directions = {
							pair<int, int>(-1, 0),
							pair<int, int>(1, 0),
							pair<int, int>(0, -1),
							pair<int, int>(0, 1) };
						
						for (pair<int, int> direction : directions) {
							int yPosNew = yPos + direction.first;
							int xPosNew = xPos + direction.second;
							
							if (yPosNew >= 0 and yPosNew < height and xPosNew >= 0 and xPosNew < width) {
								if (grid[yPosNew][xPosNew] and !flag[yPosNew][xPosNew]) {
									s.push(pair<int, int>(yPosNew, xPosNew));
									flag[yPosNew][xPosNew] = true;
								}
							}
						}
					}
				}
			}
		}
		
		
		cout << "In rectangle #" << i + 1 << " are " << numShapes << " shapes" << endl;
	}
	
    return 0;
}
