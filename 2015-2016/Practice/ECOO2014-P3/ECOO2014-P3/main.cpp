#include <iostream>

using namespace std;

int R;
int C;
char board[30][30];

int M;
string words[100];

struct Move {
    int x;
    int y;
};

int main() {
    freopen("DATA31.txt", "r", stdin);
    
    for (int test = 0; test < 5; test++) {
        cin >> R >> C;
        
        for (int r = 0; r < R; r++) {
            string line;
            cin >> line;
            
            for (int c = 0; c < C; c++) {
                board[r][c] = line[c];
            }
        }
        
        cin >> M;
        
        for (int m = 0; m < M; m++) {
            string word;
            cin >> word;
            
            for (int i = word.length() - 1; i >= 0; i--) {
                if (!('A' <= word[i] && word[i] <= 'Z')) {
                    word = word.substr(0, i) + word.substr(i + 1);
                }
            }
            
            words[m] = word;
        }
        
        
        Move jumps[] = {
            Move {-1,  0},
            Move { 1,  0},
            Move { 0, -1},
            Move { 0,  1},
            Move {-1, -1},
            Move {-1,  1},
            Move { 1,  1},
            Move { 1, -1}
        };
        
        
    }
    
    return 0;
}
