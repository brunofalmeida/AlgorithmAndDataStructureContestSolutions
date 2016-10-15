#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int G;	// number of gates
int P;	// number of planes
int planes[100001];	// gates possible - 1 to n


// returns how many more planes can be landed with configuration
int recurse(bool airport[], int nextPlane) {
	int gateRange = planes[nextPlane];
	int maximum = 0;
	
	for (int gate = 1; gate <= gateRange; gate++) {
		if (!airport[gate]) {
			airport[gate] = true;
			maximum = max(maximum, recurse(airport, nextPlane + 1) + 1);
			airport[gate] = false;
		}
	}
	
	return maximum;
}


int main() {
	scanf("%d", &G);
	scanf("%d", &P);
	
	for (int i = 0; i < P; i++)
		scanf("%d", &planes[i]);
	
	
	bool airport[100001];
	cout << recurse(airport, 0) << endl;
	
	
    return 0;
}
