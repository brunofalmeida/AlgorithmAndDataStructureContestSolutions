#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Files
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    
    
    // Input
    int N;  // number of cows
    cin >> N;

    // cows
    vector<int> positions(N);
    vector<int> speeds(N);
    
    for (int i = 0; i < N; i++) {
        cin >> positions[i]; cin >> speeds[i];
    }
    
    
    // Algorithm
    int numGroups = 1;
    int groupSpeed = speeds[0];
    
    for (int i = 1; i < N; i++) {
        if (speeds[i] < groupSpeed) {
            numGroups++;
            groupSpeed = speeds[i];
        }
        
        else if (speeds[i] == groupSpeed) {
            if ( (speeds[i] < speeds[i-1]) or (speeds[i] == speeds[i-1] and positions[i] - positions[i-1] > 1) ) {
                numGroups++;
                groupSpeed = speeds[i];
            }
        }
    }
    
    
    // Output
    cout << numGroups << endl;
    
    
    return 0;
}
