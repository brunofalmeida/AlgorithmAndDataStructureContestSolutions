#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX 999999999

using namespace std;


int n;
int heights[200000];


int maxStrength(int x) {
	int maximum = 0;
	
	// start position
	for (int i = 0; i <= n - x; i++) {
		int minimum = MAX;
		
		// current position
		for (int i2 = i; i2 < i + x; i2++) {
			minimum = min(minimum, heights[i2]);
		}
		
		maximum = max(maximum, minimum);
	}
	
	return maximum;
}


int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &heights[i]);
	}
	
	for (int x = 1; x < n; x++) {
		printf("%d ", maxStrength(x));
	}
	printf("%d\n", maxStrength(n));
	
    return 0;
}
