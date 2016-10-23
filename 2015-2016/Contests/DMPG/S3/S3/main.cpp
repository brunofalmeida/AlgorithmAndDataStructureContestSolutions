#include <iostream>

using namespace std;

bool rocketStops[100000];
int peopleStops[100000];

int main() {
    int N;  // number of stops
    int R;  // number of rocket bus stops
    int M;  // number of passengers
    
    cin >> N >> R >> M;
    
    for (int i = 0; i < R; i++) {
        int stop;
        cin >> stop;
        rocketStops[stop] = true;
    }
    
    int numRocket = 0;
    int numNormal = 0;
    
    for (int i = 0; i < M; i++) {
        cin >> peopleStops[i];
        
        if (rocketStops[peopleStops[i]] == false) {
            numNormal++;
        }
    }
    
    numRocket = M - numNormal;
    if (numRocket > numNormal) {
        int numToMove = (numRocket - numNormal) / 2;
        
        numRocket -= numToMove;
        numNormal += numToMove;
    }
    
    int total = 0;
    
    total += numRocket * (1 + numRocket) / 2;
    total += numNormal * (1 + numNormal) / 2;
    
    cout << total << endl;
    
    return 0;
}
