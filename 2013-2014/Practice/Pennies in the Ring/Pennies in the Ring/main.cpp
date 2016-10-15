#include <iostream>
using namespace std;

int main () {
    int radius, squared, counter;
    
    while (true) {
        cin >> radius;
        if (radius == 0)
            break;
        squared = radius * radius;
        counter = 0;
        
        for (int x = -radius; x <= radius; x ++) {
            for (int y = -radius; y <= radius; y ++) {
                if (x * x + y * y <= squared)
                    counter ++;
            }
        }
        
        cout << counter << endl;;
    }
    return 0;
}

