#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int MAX = 999999999;

int A, B;   // start and end
int N;      // number of planes
vector<int> costs;
vector< vector<int> > routes;
vector<int> distA(10001, MAX);
vector<int> distB(10001, MAX);


void input() {
    cin >> A >> B >> N;
    costs.resize(N);
    routes.resize(N);
    
    for (int i = 0; i < N; i++) {
        int numCities;
        cin >> costs[i] >> numCities;

        routes[i].resize(numCities);
        for (int ii = 0; ii < numCities; ii++)
            cin >> routes[i][ii];
    }
}

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);

    input();
    
    distA[A] = 0;
    distB[B] = 0;
    for (int i = 0; i < N; i++) {
        vector<int>::iterator itA = find(routes[i].begin(), routes[i].end(), A);
        if (itA != routes[i].end()) {
            for (vector<int>::iterator it2 = itA + 1; it2 != routes[i].end(); it2++)
                distA[*it2] = min(distA[*it2], costs[i]);
        }

        vector<int>::iterator itB = find(routes[i].begin(), routes[i].end(), B);
        if (itB != routes[i].end()) {
            for (vector<int>::iterator it2 = routes[i].begin(); it2 != itB; it2++)
                distB[*it2] = min(distB[*it2], costs[i]);
        }
    }
    
    int minimum = MAX;
    for (int i = 1; i <= 10000; i++)
        minimum = min(minimum, distA[i] + distB[i]);

    if (minimum < MAX)
        cout << minimum << endl;
    else
        cout << -1 << endl;

    return 0;
}
