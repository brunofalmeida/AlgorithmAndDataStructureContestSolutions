#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int henchmen[1];
int doors[1];

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> henchmen[i];
    }
    
    vector<int> doorsSorted(M);
    for (int i = 0; i < M; i++) {
        cin >> doors[i];
        doorsSorted[i] = doors[i];
    }
    
    sort(doorsSorted.begin(), doorsSorted.end());
    
    vector<bool> doorsSortedClosed(M, true);
    
    int minIndex = 0;
    int minDoor = doorsSorted[minIndex];
    
    for (int i = 0; i < M; i++) {
        int door = doors[i];
    }
    
    return 0;
}
