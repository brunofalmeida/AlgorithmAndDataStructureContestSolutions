#include <iostream>
#include <cstdio>
#include <set>
#include <utility>

using namespace std;

int main() {
	int m;
	scanf("%d", &m);
	
	int h1, a1;
	scanf("%d %d", &h1, &a1);
	
	int x1, y1;
	scanf("%d %d", &x1, &y1);
	
	int h2, a2;
	scanf("%d %d", &h2, &a2);
	
	int x2, y2;
	scanf("%d %d", &x2, &y2);
	
	
	int seconds = 0;
	
	set< pair<int, int> > states;
	states.insert(make_pair(h1, h2));
	
	while (true) {
		seconds++;
		h1 = (x1 * h1 + y1) % m;
		h2 = (x2 * h2 + y2) % m;
		
		if (h1 == a1 and h2 == a2) {
			printf("%d\n", seconds);
			break;
		} else if (states.find(make_pair(h1, h2)) != states.end()) {
			printf("-1\n");
			break;
		} else {
			states.insert(make_pair(h1, h2));
		}
	}
	
	
    return 0;
}
