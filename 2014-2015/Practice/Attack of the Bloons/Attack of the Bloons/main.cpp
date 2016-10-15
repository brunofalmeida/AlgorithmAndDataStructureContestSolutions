#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int L;          // number of cells

int N;          // number of towers
vector<int> C;  // cell location
vector<int> R;  // fire radius
vector<int> D;  // HP damage per second

int M;          // number of bloons
vector<int> H;  // bloon HP

int T;          // number of scenarios


void input() {
    cin >> L >> N;
    
    C.resize(N);
    R.resize(N);
    D.resize(N);
    for (int i = 0; i < N; i++)
        cin >> C[i] >> R[i] >> D[i];
    
    cin >> M;
    
    H.resize(M);
    for (int i = 0; i < M; i++)
        cin >> H[i];
}


int main() {
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        input();
        
        vector<long long> course(L + 1, 0);
        for (int i = 0; i < N; i++) {
            for (int l = max(C[i] - R[i], 1); l <= min(C[i] + R[i], L); l++)
                course[l] += D[i];
        }
        
        vector<long long> prefix(L + 1, 0);
        for (int l = 1; l <= L; l++)
            prefix[l] = prefix[l - 1] + course[l];
        
        for (int i = 0; i < M; i++) {
            for (int l = 1; l <= L; l++) {
                if (prefix[l] >= H[i]) {
                    cout << l << endl;
                    break;
                }
            }
            
            if (H[i] > prefix[L])
                cout << "Bloon leakage" << endl;
        }
    }
    
    return 0;
}
