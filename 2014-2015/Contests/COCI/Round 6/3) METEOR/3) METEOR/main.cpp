#include <iostream>
#include <vector>

using namespace std;

int main() {
	//freopen("meteor.dummy.in.2", "r", stdin);
	
	int R, S;	// rows, columns
	cin >> R >> S;
	
	vector< vector<char> > photo(R, vector<char> (S));
	for (int r = 0; r < R; r++) {
		string row;
		cin >> row;
		for (int c = 0; c < S; c++)
			photo[r][c] = row[c];
	}
	
	
	while (true) {
		bool moveDown = true;
		
		for (int r = 0; r < R - 1; r++) {
			for (int c = 0; c < S; c++) {
				if (photo[r][c] == 'X' and photo[r+1][c] == '#') {
					moveDown = false;
					break;
				}
			}
		}
		
		if (moveDown) {
			for (int r = R - 2; r >= 0; r--) {
				for (int c = 0; c < S; c++) {
					if (photo[r][c] == 'X') {
						photo[r][c] = '.';
						photo[r+1][c] = 'X';
					}
				}
			}
		}
		else {
			break;
		}
	}
	
	
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < S; c++)
			cout << photo[r][c];
		cout << endl;
	}
	
	
    return 0;
}
