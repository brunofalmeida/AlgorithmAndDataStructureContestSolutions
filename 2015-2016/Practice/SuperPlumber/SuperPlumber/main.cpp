#include <iostream>
#include <algorithm>

using namespace std;




struct Max {
    int right;
    int up;
    int down;
};

const string digits = "123456789";

int m;  // number of rows
int n;  // number of columns

char grid[100][100];
Max dp[100][100];




bool isSafe(int row, int col) {
    if (grid[row][col] != '*') {
        return true;
    } else {
        return false;
    }
}

bool isDigit(int row, int col) {
    if (digits.find(grid[row][col]) != string::npos) {
        return true;
    } else {
        return false;
    }
}

int toInt(int row, int col) {
    return (int) grid[row][col] - 48;
}




int main() {
    while (true) {
        
        // Input
        cin >> m >> n;
        
        if (m == 0 && n == 0) {
            break;
        }
        
        for (int row = m - 1; row >= 0; row--) {
            string line;
            cin >> line;
            
            for (int col = 0; col < n; col++) {
                grid[row][col] = line[col];
            }
        }
        
        
        
        
        // DP
        
        // Set initial coin values
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (isDigit(row, col)) {
                    dp[row][col].right = toInt(row, col);
                    dp[row][col].up = toInt(row, col);
                    dp[row][col].down = toInt(row, col);
                } else {
                    dp[row][col].right = 0;
                    dp[row][col].up = 0;
                    dp[row][col].down = 0;
                }
            }
        }
        
        // Left column
        for (int col = 0; col < 1; col++) {
            
            // Go up column
            for (int row = 0; row < m - 1; row++) {
                // Update up square
                if (isSafe(row, col) && isSafe(row + 1, col)) {
                    dp[row + 1][col].up += dp[row][col].up;
                }
            }
            
            // Go up column
            for (int row = 0; row < m; row++) {
                // Update right square
                if (isSafe(row, col) && isSafe(row, col + 1)) {
                    dp[row][col + 1].right += dp[row][col].up;
                }
            }
            
        }
    
        // Middle columns
        for (int col = 1; col < n - 1; col++) {
            
            // Go up column
            for (int row = 0; row < m - 1; row++) {
                // Update up square
                if (isSafe(row, col) && isSafe(row + 1, col)) {
                    dp[row + 1][col].up += max(dp[row][col].up, dp[row][col].right);
                }
            }
            
            // Go down column
            for (int row = m - 1; row > 0; row--) {
                // Update down square
                if (isSafe(row, col) && isSafe(row - 1, col)) {
                    dp[row - 1][col].down += max(dp[row][col].down, dp[row][col].right);
                }
            }
            
            // Go up column
            for (int row = 0; row < m; row++) {
                // Update right square
                if (isSafe(row, col) && isSafe(row, col + 1)) {
                    dp[row][col + 1].right += max( max(dp[row][col].up, dp[row][col].down), dp[row][col].right );
                }
            }
            
        }
        
        // Right column
        for (int col = n - 1; col < n; col++) {
            
            // Go down column
            for (int row = m - 1; row > 0; row--) {
                // Update down square
                if (isSafe(row, col) && isSafe(row - 1, col)) {
                    dp[row - 1][col].down += max(dp[row][col].down, dp[row][col].right);
                }
            }
            
        }
        
        cout << max( max(dp[0][n - 1].up, dp[0][n - 1].down), dp[0][n - 1].right ) << endl;
        
    }
    
    
    
    
    return 0;
}
