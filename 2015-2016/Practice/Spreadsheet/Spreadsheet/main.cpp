#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;


int grid[11][10];       // number results
vector< pair<int, int> > graph[11][10];


pair<int, int> getRowCol(string pos) {
    int row = (int)pos[0] - 64;
    int col = (int)pos[1] - 48;
    return make_pair(row, col);
}


int main() {
    
    for (int row = 1; row < 11; row++) {
        for (int col = 1; col < 10; col++) {
            string cell;
            cin >> cell;
            
            try {
                grid[row][col] = stoi(cell);
            } catch (invalid_argument e) {
                grid[row][col] = 0;
                
                for (int i = 2; i < cell.length(); i++) {
                    if (cell[i] == '+') {
                        graph[row][col].push_back(getRowCol(cell.substr(i - 2, 2)));
                    }
                }
                graph[row][col].push_back(getRowCol(cell.substr(cell.length() - 2, 2)));
            }
        }
    }
    
    bool changed = true;
    
    while (changed) {
        changed = false;
        
        for (int row = 1; row < 11; row++) {
            for (int col = 1; col < 10; col++) {
                
                if (graph[row][col].size() > 0) {
                    for (int i = 0; i < graph[row][col].size(); i++) {
                        
                        int nextRow = graph[row][col][i].first;
                        int nextCol = graph[row][col][i].second;
                        
                        if (graph[nextRow][nextCol].size() == 0) {
                            grid[row][col] += grid[nextRow][nextCol];
                            graph[row][col].erase(graph[row][col].begin() + i);
                            changed = true;
                        }
                    }
                }
            }
        }
    }
    
    for (int row = 1; row < 11; row++) {
        for (int col = 1; col < 10; col++) {
            if (graph[row][col].size() == 0) {
                cout << grid[row][col] << " ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
