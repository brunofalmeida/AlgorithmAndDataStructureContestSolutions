#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool canPlay(const vector<int>& stalks) {
    return (stalks[stalks.size() - 1] - stalks[0] > 1);
}

void mirko(vector<int>& stalks) {
    // find last stalk with minimal height
    int min = stalks[0];
    int iMin = 0;
    
    while (true) {
        if (stalks[iMin + 1] == min)
            iMin++;
        else
            break;
    }
    
    stalks[iMin] = stalks[iMin + 1];
}

void slavko(vector<int>& stalks) {
    // find first stalk with maximum height
    int max = stalks[stalks.size() - 1];
    int iMax = stalks.size() - 1;
    
    while (true) {
        if (stalks[iMax - 1] == max)
            iMax--;
        else
            break;
    }
    
    stalks[iMax] = stalks[iMax - 1];
}


int main() {
    // File
    // freopen("psenica.dummy.in.3", "r", stdin);
    
    
    // Input
    int N; cin >> N;
    
    vector<int> stalks(N);
    for (int i = 0; i < N; i++)
        cin >> stalks[i];
    sort(stalks.begin(), stalks.end());
    
    
    // Algorithm, Output
    while (true) {
        if (canPlay(stalks)) {
            mirko(stalks);
        }
        else {
            cout << "Slavko" << endl;
            cout << stalks[0] << " " << stalks[stalks.size() - 1] << endl;
            break;
        }
        
        if (canPlay(stalks)) {
            slavko(stalks);
        }
        else {
            cout << "Mirko" << endl;
            cout << stalks[0] << " " << stalks[stalks.size() - 1] << endl;
            break;
        }
    }
    
    
    return 0;
}
