// http://wcipeg.com/problem/ccc08j5
// Note: This is the junior (J5) version of the problem, not the senior (S5) version
// This solution is too slow to pass the senior version of the problem


#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > reactions = {
    {2, 1, 0, 2},
    {1, 1, 1, 1},
    {0, 0, 2, 1},
    {0, 3, 0, 0},
    {1, 0, 0, 1}
};

bool isWinning(int A, int B, int C, int D) {
    for (int i = 0; i < reactions.size(); i++) {
        vector<int> reaction = reactions[i];
        
        if (A >= reaction[0] && B >= reaction[1] && C >= reaction[2] && D >= reaction[3]) {
            if (isWinning(A - reaction[0], B - reaction[1], C - reaction[2], D - reaction[3]) == false) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        
        if (isWinning(A, B, C, D)) {
            cout << "Patrick" << endl;
        } else {
            cout << "Roland" << endl;
        }
    }
    
    return 0;
}
