#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Files
    freopen("crosswords.in", "r", stdin);
    freopen("crosswords.out", "w", stdout);
    
    
    // Input
    // dimensions
    int N;  // number of rows (y)
    int M;  // number of columns (x)
    cin >> N; cin >> M;
    
    // grid
    vector< vector<bool> > grid( N + 1, vector<bool> (M + 1) ); // [row][column]
    for (int y = 1; y <= N; y++) {
        string row;
        cin >> row;
        for (int x = 1; x <= M; x++) {
            if (row[x-1] == '.')
                grid[y][x] = true;
            else
                grid[y][x] = false;
        }
    }
    
    
    // Algorithm
    vector< pair<int, int> > clues;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            if (
                ( (grid[y][x] and x <= M - 2) and ( (!grid[y][x-1]) or (x == 1) ) and ( grid[y][x+1] and grid[y][x+2] )  ) or
                ( (grid[y][x] and y <= N - 2) and ( (!grid[y-1][x]) or (y == 1) ) and ( grid[y+1][x] and grid[y+2][x] )  )
                )
                clues.push_back(make_pair(y, x));
        }
    }
    
    
    // Output
    cout << clues.size() << endl;
    
    for (int i = 0; i < clues.size(); i++)
        cout << clues[i].first << " " << clues[i].second << endl;
    
    
    return 0;
}
