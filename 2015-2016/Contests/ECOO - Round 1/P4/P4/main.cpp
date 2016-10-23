#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int cx, cy;
struct p {
    int x, y;
    char v;
} h[150];
vector<pair<int,char>> sorted;
bool ex[500][500];


int distance(int ax, int bx, int ay, int by)
{
    return (ax-bx) * (ax-bx) + (ay-by)*(ay-by);
}

bool get(int currx, int curry)
{
    int r = 0, d = 0;
    sorted.clear();
    for (int i = 0; i < 100; i ++)
    {
        int dist = distance(currx, h[i].x, curry, h[i].y);
        sorted.push_back(make_pair(dist, h[i].v));
    }
    sort(sorted.begin(), sorted.end());
    sorted.push_back(make_pair(-1, -1));
    int last = 100, i = 0; int pos = 1;
    for (i = 0; i < 100; i ++)
    {
        if (sorted[i].first != sorted[last].first)
        {
            last = i;
            pos = i + 1;
        }
        if (pos <= 3)
        {
            if (sorted[i].second == 'R')
                r ++;
            else d++;
        }
    }
    if (r > d)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int rans, dans;
void _main()
{
    memset(ex, 0, sizeof ex);
    scanf("%d%d", &cx, &cy);
    cx += 200; cy += 200;
    rans = 0; dans = 0;
    for (int i = 0; i < 100; i++)
    {
        cin >> h[i].x >> h[i].y >> h[i].v;
        h[i].x += 200;
        h[i].y += 200;
        ex[h[i].x][h[i].y] = 1;
    }
    
    for (int x1 = max(cx - 50, 0); x1 <= min(cx + 50, 400); x1++) {
        int y1  = cy - floor( sqrt(pow(50, 2) - pow(x1 - cx, 2)) );
        int y2  = cy + floor( sqrt(pow(50, 2) - pow(x1 - cx, 2)) );
        for (int y = y1; y <= y2; y ++)
        {
            if (ex[x1][y]) continue;
            if (get(x1, y)) dans ++;
            else rans ++;
        }
    }
    
    printf("%.1f\n", (double) (dans) / (double) (rans + dans) * (double) 100);
}
int main()
{
    freopen("DATA42.txt","r", stdin);
    int T = 10;
    while (T --> 0)
    {
        _main();
    }
}
