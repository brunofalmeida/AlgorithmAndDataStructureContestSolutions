#include <iostream>
#include <cstdio>
#include <set>

using namespace std;


int n;				// number of kinds of beer
int q;				// number of queries
int foam[200001];	// milliliters of foam in each kind of beer


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}


int main() {
	scanf("%d %d", &n, &q);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &foam[i]);
	}
	
	
	set<int> shelf;
	int score = 0;
	
	// queries
	for (int i = 0; i < q; i++) {
		int x;	// index of beer to add/remove
		scanf("%d", &x);
		
		// add x
		if (shelf.find(x) == shelf.end()) {
			for (int beer : shelf) {
				if (gcd(foam[beer], foam[x]) == 1) {
					score++;
				}
			}
			
			shelf.insert(x);
		}
		
		// remove x
		else {
			shelf.erase(x);
			
			for (int beer : shelf) {
				if (gcd(foam[beer], foam[x]) == 1) {
					score--;
				}
			}
		}
		
		printf("%d\n", score);
	}
	
	
    return 0;
}
