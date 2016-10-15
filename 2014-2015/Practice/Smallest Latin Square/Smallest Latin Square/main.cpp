#include <iostream>
#include <vector>

using namespace std;


int M;  // number of test cases
int N;  // size of square
vector< vector<int> > grid;   // 2D - [y][x]


bool isInRow(int y, int num) {
    for (int x = 1; x <= N; x++) {
        if (grid[y][x] == num)
            return true;
    }
    
    return false;
}

bool isInColumn(int x, int num) {
    for (int y = 1; y <= N; y++) {
        if (grid[y][x] == num)
            return true;
    }
    
    return false;
}

bool canSolveGrid() {
    for (int y = 2; y <= N; y++) {      // for each row
        for (int x = 2; x <= N; x++) {  // for each square
            if (grid[y][x] == 0) {      // if square has not been solved
                
                for (int n = 1; n <= N; n++) {                          // for each possible number
                    if ( (!isInRow(y, n)) and (!isInColumn(x, n)) ) {   // if number can be put there
                        
                        grid[y][x] = n;                                 // set square to number
                        
                        if (canSolveGrid())
                            break;
                        else
                            grid[y][x] = 0;
                    }
                }
                
                if (grid[y][x] == 0)
                    return false;
            }
        }
    }
    
    return true;
}

int main() {
    // Input
    cin >> M;
    
    
    // For each test case
    for (int m = 0; m < M; m++) {
        // Input
        cin >> N;
        
        // resize grid
        grid.resize(N + 1);
        for (int i = 0; i < N + 1; i++) {
            grid[i].resize(N + 1);
            for (int ii = 0; ii < N + 1; ii++)
                grid[i][ii] = 0;
        }
        
        
        // Algorithm
        
        // top row
        for (int x = 1; x <= N; x++)
            grid[1][x] = x;
        
        // left side
        for (int y = 1; y <= N; y++)
            grid[y][1] = y;
        
        // diagonal
        for (int x = N, y = 1;  x >= 1;  x--, y++)
            grid[y][x] = N;
        
        // remaining
        canSolveGrid();
        
        
        // Output
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x < N; x++)
                cout << grid[y][x] << " ";
            cout << grid[y][N] << endl;
        }
    }
    
    
    return 0;
}
