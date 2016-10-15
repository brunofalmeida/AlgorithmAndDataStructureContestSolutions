#include <iostream>
#include <cstdio>
using namespace std;

struct rect {
	int l,w;
}rects[11];

int n,bound,perimeter = -1;
bool grid[31][31];

bool check(int sx,int sy, int l, int w) {
	if ((sx + l -1 > bound) || (sy + w-1>bound))
		return false;
	
	for (int i = sx;i<=sx+l-1;i++) {
		for (int j = sy;j<=sy+w-1;j++) {
			if (grid[i][j])
				return false;
		}
	}
	return true;
}

bool finalcheck(int &a, int &b, int &c, int &d) {
	for (int i = 1;i<=bound;i++) {
		for (int j = 1;j<=bound;j++) {
			if (grid[i][j]) {
				a = min(a,j);
				b = min(b,i);
				c = max(c,j);
				d = max(d,i);
			}
		}
	}
	
	for (int i = b;i<=d;i++) {
		for (int j = a;j<=c;j++) {
			if (!grid[i][j])
				return false;
		}
	}

	return true;
}
	
void fill(int sx,int sy, int l, int w) {
	for (int i = sx;i<=sx+l-1;i++) {
		for (int j = sy;j<=sy+w-1;j++)
			grid[i][j] = 1;
	}
}

void unfill(int sx,int sy, int l, int w) {
	for (int i = sx;i<=sx+l-1;i++) {
		for (int j = sy;j<=sy+w-1;j++)
			grid[i][j] = 0;
	}
}

void recurse(int pos) {
	if (pos == n+1) {
		int a=999999,b=999999,c=-1,d=-1; // left,top,right,bottom
		if (finalcheck(a,b,c,d)) {
			perimeter = max(perimeter,(c-a+d-b+2)*2);
		}
		return;
	}
	
	for (int i = 1;i<=bound - rects[pos].l + 1;i++) {
		for (int j = 1;j<=bound - rects[pos].w + 1;j++) {
			if (!grid[i][j]) {
				if (check(i,j,rects[pos].l,rects[pos].w)) {
					fill(i,j,rects[pos].l,rects[pos].w);
					recurse(pos+1);
					unfill(i,j,rects[pos].l,rects[pos].w);
				}
				
				if (check(i,j,rects[pos].w,rects[pos].l)) {
					fill(i,j,rects[pos].w,rects[pos].l);
					recurse(pos+1);
					unfill(i,j,rects[pos].w,rects[pos].l);
				}
			}
		}
	}
}

int main() {
	freopen("DATA40.txt", "r", stdin);
	
	for (int test = 0; test < 10; test++) {
		scanf("%d",&n);
		
		bound = 0;
		perimeter = -1;
		
		for (int i = 1;i<=n;i++) {
			scanf("%d %d",&rects[i].l,&rects[i].w);
			bound += max(rects[i].l,rects[i].w);
		}
		bound = min(bound, 30);
		
		for (int i = 1;i<=bound;i++)
			for (int j = 1;j<=bound;j++)
				grid[i][j] = 0;
		
		if (n <= 5) {
			recurse(1);
		
			if (perimeter == -1)
				printf("Not Possible\n");
			else
				printf("%d\n", perimeter);
		} else {
			printf("Not Possible\n");
		}
	}
	
	return 0;
}