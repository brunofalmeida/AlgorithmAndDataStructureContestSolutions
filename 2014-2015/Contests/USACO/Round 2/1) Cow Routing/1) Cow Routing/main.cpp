#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    
    int A, B;   // start and end
    int N;      // number of planes
    cin >> A >> B >> N;
    
    int minCost = 999999;
    
    for (int i = 0; i < N; i++) {
        int cost, numCities;
        cin >> cost >> numCities;
        
        vector<int> cities(numCities);
        for (int ii = 0; ii < numCities; ii++)
            cin >> cities[ii];
        
        if (cost < minCost) {
            vector<int>::iterator iA = find( cities.begin(), cities.end(), A);
            if (iA != cities.end()) {
                if (find(iA + 1, cities.end(), B) != cities.end())
                    minCost = cost;
            }
        }
    }
    
    if (minCost != 999999)
        cout << minCost << endl;
    else
        cout << -1 << endl;
    
    return 0;
}
