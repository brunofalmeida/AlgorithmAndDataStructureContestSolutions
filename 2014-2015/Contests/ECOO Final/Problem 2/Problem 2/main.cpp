#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct shape {
	bool type;
	int r,c,b,h;
}shapes[501];
int b,h,n,B,H;
vector<string> colors;
string line;
map<string,int> colors;
double area (int x1, int y1, int x2, int y2, int x3, int y3) {
	double ans = double(x1-x2)*double(y2-y3)-(double)(x2-x3)*(double)(y1-y2);
	if (ans <0) ans = -ans;
	return ans/2;
}
bool checkT(int x1, int y1, int x2, int y2, int x3, int y3,int px, int py) {
	double area1 = area(x1,y1,x2,y2,x3,y3);
	double a1 = area(px,py,x2,y2,x3,y3);
	double a2 = area(x1,y1,px,py,x3,y3);
	double a3 = area(x1,y1,x2,y2,px,py);
	return (a1+a2+a3 == area1);
}

bool checkR(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4, int px, int py) {
	if (min(min(x1,x2),min(x3,x4))<= px && px <= (min(min(x1,x2),min(x3,x4))))
		if (min(min(y1,y2),min(y3,y4))<= py && py <= (min(min(y1,y2),min(x3,x4))))
			return true;
	return false;

}
int main() {
	for (int t = 0;t<10;t++) {
		scanf("%d%d",&B,&H);
		getline(cin,line);
		int idx = 0;
		while (line.find(" ") != line.end()) {
			int index = line.find(" ");
			string word = line.substr(0,index);
			if (!colors.count(word)) {
				colors[word] = idx++;
			}
			line = line.substr(index, line.length() - index);
		}
		
		cin >> n;
		for (int i = 1;i<=n;i++) {
			char type;
			cin >> type;
			if (type == 'R')  {
				shapes[i].type = 1;
				scanf("%d%d%d%d",&shapes[i].r,&shapes[i].c,&shapes[i].b,&shapes[i].h);
			} else {
				shapes[i].type = 0;
				scanf("%d%d%d",&shapes[i].r,&shapes[i].c,&shapes[i].b);
			}
		}
		int points;
		cin >> points;
		for (int i = 1;i<=points;i++) {
			int r,c;
			scanf("%d%d",&r,&c);
			int cnt = 0;
			for (int j = 1;j<=n;j++) {
				if (!shapes[j].type) {
					int x1 = shapes[i].r;
					int y1 = shapes[i].c;
					int y2 = y1;
					int x2 = x1+B*shapes[i].b;
					int x3 = x1;
					int y3 = y1+shapes[i].b*H;
					if (checkT(x1,y1,x2,y2,x3,y3,r,c)) cnt ++;
				} else {
					int x1 = shapes[i].r;
					int y1 = shapes[i].c;
					int x2 = x1;
					int y2 = y1+H*shapes[i].h;
					int x3 = x1+shapes[i].b*B;
					int y3 = y1;
					int x4 = x3;
					int y4 = y2;
					if (checkR(x1,y1,x2,y2,x3,y3,x4,y4,r,c)) cnt ++;
				}
			}
		}
	}
}