#include <iostream>

using namespace std;

struct Beacon {
	int x;
	int y;
	int r;
};

Beacon beacons[501];
bool graph[501][501];

int main() {
	int B, Q;
	scanf("%d %d", &B, &Q);
	
	for (int i = 1; i <= B; i++) {
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		
		beacons[i] = Beacon{x, y, r};
	}
	
	for (int i = 1; i <= B; i++) {
		for (int j = 1; j <= B; j++) {
			Beacon beaconI = beacons[i];
			Beacon beaconJ = beacons[j];
			
			if ( (beaconI.x - beaconJ.x) * (beaconI.x - beaconJ.x) + (beaconI.y - beaconJ.y) * (beaconI.y - beaconJ.y) <=
				(beaconI.r * beaconI.r) ) {
				graph[i][j] = true;
			}
			
			if ( (beaconI.x - beaconJ.x) * (beaconI.x - beaconJ.x) + (beaconI.y - beaconJ.y) * (beaconI.y - beaconJ.y) <=
				(beaconJ.r * beaconJ.r) ) {
				graph[j][i] = true;
			}
		}
	}
	
	for (int j = 1; j <= B; j++) {
		for (int i = 1; i <= B; i++) {
			for (int k = 1; k <= B; k++) {
				if (graph[i][j] and graph[j][k])
					graph[i][k] = true;
			}
		}
	}
	
	for (int i = 0; i < Q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		if (graph[a][b]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
    return 0;
}
