#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, M;       // grid size

int K;          // number of icings
vector<int> xL; // icing start
vector<int> yL;
vector<int> XL; // icing end
vector<int> YL;

int Q;          // number of piece choices
vector<int> AL; // piece start
vector<int> BL;
vector<int> CL; // piece end
vector<int> DL;


void input() {
    scanf("%d %d %d", &N, &M, &K);
    
    xL.resize(K);
    yL.resize(K);
    XL.resize(K);
    YL.resize(K);
    for (int i = 0; i < K; i++)
        scanf("%d %d %d %d", &xL[i], &yL[i], &XL[i], &YL[i]);
    
    scanf("%d", &Q);
    
    AL.resize(Q);
    BL.resize(Q);
    CL.resize(Q);
    DL.resize(Q);
    for (int i = 0; i < Q; i++)
        scanf("%d %d %d %d", &AL[i], &BL[i], &CL[i], &DL[i]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    
    input();
    
    // difference array
    vector< vector<long long> > D(N + 1, vector<long long> (M + 1, 0));
    for (int i = 0; i < K; i++) {
        int x = xL[i];
        int y = yL[i];
        int X = XL[i];
        int Y = YL[i];
        
        D[x][y]++;
        if (X + 1 <= N and Y + 1 <= M)
            D[X + 1][Y + 1]++;
        
        if (Y + 1 <= M)
            D[x][Y + 1]--;
        if (X + 1 <= N)
            D[X + 1][y]--;
    }
    
    // actual array
    vector< vector<long long> > A(N + 1, vector<long long> (M + 1, 0));
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++)
            A[x][y] = A[x - 1][y] + A[x][y - 1] - A[x - 1][y - 1] + D[x][y];
    }
    
    // prefix sum array
    vector< vector<long long> > P(N + 1, vector<long long> (M + 1, 0));
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++)
            P[x][y] = P[x - 1][y] + P[x][y - 1] - P[x - 1][y - 1] + A[x][y];
    }
    
    // output
    for (int i = 0; i < Q; i++) {
        int A = AL[i];
        int B = BL[i];
        int C = CL[i];
        int D = DL[i];
        
        cout << (P[C][D] - P[A - 1][D] - P[C][B - 1] + P[A - 1][B - 1]) << endl;
    }
    
    return 0;
}
