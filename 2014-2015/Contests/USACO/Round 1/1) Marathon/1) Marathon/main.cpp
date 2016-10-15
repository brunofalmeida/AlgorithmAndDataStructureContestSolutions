#include <iostream>
#include <vector>

using namespace std;


struct Point {
    int x;
    int y;
};

int getDistance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}


int main() {
    // files
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    
    
    // input
    int N;
    cin >> N;   // number of checkpoints
    
    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x; cin >> points[i].y;
    }
    
    
    // algorithm - calculate distances
    int distance = 0;
    int maxSaved = 0;
    
    for (int i = 0; i < N - 2; i++) {   // skips last 2 points
        Point p1 = {points[i].x, points[i].y};
        Point p2 = {points[i+1].x, points[i+1].y};
        Point p3 = {points[i+2].x, points[i+2].y};
        
        distance += getDistance(points[i].x, points[i].y, points[i+1].x, points[i+1].y);
        
        int saved = ( getDistance(p1.x, p1.y, p2.x, p2.y) + getDistance(p2.x, p2.y, p3.x, p3.y) ) -
                    ( getDistance(p1.x, p1.y, p3.x, p3.y) );
        if (saved > maxSaved)
            maxSaved = saved;
    }
    
    Point p1 = {points[N-2].x, points[N-2].y};
    Point p2 = {points[N-1].x, points[N-1].y};
    distance += getDistance(p1.x, p1.y, p2.x, p2.y);
    
    distance -= maxSaved;
    
    
    // output
    cout << distance << endl;
    
    
    return 0;
}
