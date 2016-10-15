#include <iostream>
#include <cmath>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    
    const double PRECISION = 0.000001;
    const double ERROR = 0.000000000001;
    
    
    double x1, y1;
    cin >> x1 >> y1;
    
    double x2, y2;
    cin >> x2 >> y2;
    
    double distance;
    cin >> distance;
    
    
    cout.setf(ios::fixed);
    cout.precision(6);
    
    for (double x = x1 - distance; x <= x1 + distance; x += PRECISION) {
        double DEy = sqrt( pow(distance,2) - pow(x-x1,2) );
        
        double y = y1 - DEy;
        if (  abs( distance - sqrt(pow(x-x2, 2) + pow(y-y2, 2)) )  <=  ERROR  )
            cout << x << " " << y << endl;
        
        y = y1 + DEy;
        if (  abs( distance - sqrt(pow(x-x2, 2) + pow(y-y2, 2)) )  <=  ERROR  and  DEy != 0.0  )
            cout << x << " " << y << endl;
    }
    
    
    return 0;
}
