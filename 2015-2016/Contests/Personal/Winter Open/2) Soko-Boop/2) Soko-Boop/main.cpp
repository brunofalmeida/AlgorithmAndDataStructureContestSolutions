#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

enum {
    LEFT = 0,
    RIGHT = 3,
    UP = 2,
    DOWN = 1
};

int R, C;
char grid[30][30];

int rX, cX;

int recurse(int rP, int cP, int rB, int cB, int last) {
    if (rP == rX && cP == cX) {
        return 0;
    }
    
    int minimum = 999999999;
    
    vector< pair<int, int> > moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < moves.size(); i++) {
        if (i != last) {
            pair<int, int> move = moves[i];
            
            int rPNext = rP + move.first;
            int cPNext = cP + move.second;
            
            if (0 <= rPNext && rPNext < R && 0 <= cPNext && cPNext < C && grid[rPNext][cPNext] != '#') {
                
                // move player and box
                if (grid[rPNext][cPNext] == 'B') {
                    int rBNext = rB + move.first;
                    int cBNext = cB + move.second;
                    
                    if (0 <= rBNext && rBNext < R && 0 <= cBNext && cBNext < C && grid[rBNext][cBNext] != '#') {
                        grid[rBNext][cBNext] = 'B';
                        grid[rPNext][cPNext] = 'P';
                        grid[rP][cP] = '.';
                        
                        minimum = min(minimum, recurse(rPNext, cPNext, rBNext, cBNext, i));
                        
                        grid[rP][cP] = 'P';
                        grid[rPNext][cPNext] = 'B';
                        grid[rBNext][cBNext] = '.';
                    }
                }
                
                // move player
                else if (grid[rPNext][cPNext] != '#') {
                    grid[rPNext][cPNext] = 'P';
                    grid[rP][cP] = '.';
                    
                    minimum = min(minimum, recurse(rPNext, cPNext, rB, cB, i));
                    
                    grid[rP][cP] = 'P';
                    grid[rPNext][cPNext] = '.';
                }
            }
        }
        
    }
    
    return minimum;
}

int main() {
    int rP = 0, cP = 0;
    int rB = 0, cB = 0;
    cin >> R >> C;
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> grid[r][c];
            
            if (grid[r][c] == 'X') {
                rX = r;
                cX = c;
            } else if (grid[r][c] == 'P') {
                rP = r;
                cP = c;
            } else if (grid[r][c] == 'B') {
                rB = r;
                cB = c;
            }
        }
    }
    
    cout << recurse(rP, cP, rB, cB, 4) << endl;
    
    return 0;
}
