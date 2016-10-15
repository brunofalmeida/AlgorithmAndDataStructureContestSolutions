#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int BFS(int x1, int y1, int x2, int y2, const vector< vector<int> >& grid);


int main()
{
    // input
    int T;  // number of stationary hiders
    int N;  // number of rows
    int M;  // number of columns
    
    cin >> T; cin >> M; cin >> T;
    
    vector< vector<bool> > grid( M, vector<bool>(N, true) );
    pair<int, int> griffy;
    vector< pair<int, int> > hiders;
    
    for (int y = 0; y < N; y++)
    {
        string row;
        cin >> row;
        
        for (int x = 0; x < M; x++)
        {
            if (row[x] == 'G')
                griffy = make_pair(x, y);
            else if (row[x] == 'H')
                hiders.push_back( make_pair(x, y) );
            else if (row[x] == 'X')
                grid[x][y] = false;
        }
    }
    
    return 0;
}
