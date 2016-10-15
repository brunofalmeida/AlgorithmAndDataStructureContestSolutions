#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int M;  // number of E-W streets (y)
int N;  // number of N-S streets (x)

int K;              // number of networks
vector<int> xList;  // x-coordinate
vector<int> yList;  // y-coordinate
vector<int> BList;  // bitrate
vector<int> RList;  // radius


void input() {
    scanf("%d", &M);
    scanf("%d", &N);
    scanf("%d", &K);
    
    xList.resize(K);
    yList.resize(K);
    BList.resize(K);
    RList.resize(K);
    for (int i = 0; i < K; i++)
        scanf("%d %d %d %d", &xList[i], &yList[i], &RList[i], &BList[i]);
}

int main() {
    input();
    
    // difference array
    vector< vector<int> > D(N + 1, vector<int> (M + 1, 0));
    for (int i = 0; i < K; i++) {
        int x = xList[i];
        int y = yList[i];
        int B = BList[i];
        int R = RList[i];
        
        for (int x1 = max(x - R, 1); x1 <= min(x + R, N); x1++) {
            int y1  = y - floor( sqrt(pow(R, 2) - pow(x1 - x, 2)) );
            int y2  = y + floor( sqrt(pow(R, 2) - pow(x1 - x, 2)) );
            
            D[x1][max(y1, 1)] += B;
            if (y2 + 1 <= M)
                D[x1][y2 + 1] -= B;
        }
    }
    
    // actual array
    vector< vector<int> > A(N + 1, vector<int> (M + 1, 0));
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++)
            A[x][y] = A[x][y - 1] + D[x][y];
    }
    
    // maximum bitrate
    int max = 0;
    int counter = 0;
    
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++) {
            if (A[x][y] == max) {
                counter++;
            }
            else if (A[x][y] > max) {
                max = A[x][y];
                counter = 1;
            }
        }
    }
    
    cout << max << endl;
    cout << counter << endl;
    
    return 0;
}
