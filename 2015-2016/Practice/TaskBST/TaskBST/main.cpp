#include <iostream>
#include <map>

using namespace std;


int main() {
    int N;
    scanf("%d", &N);
    
    map<int, int> depths;
    long long counter = 0;
    
    for (int i = 0; i < N; ++i) {
        int X;
        scanf("%d", &X);
        
        map<int, int>::iterator iter = depths.lower_bound(X);
        
        int depth = 0;
        
        if (iter != depths.end()) {
            depth = iter->second + 1;
        }
        
        if (iter != depths.begin()) {
            depth = max(depth, (--iter)->second + 1);
        }
        
        depths[X] = depth;
        counter += depth;
        
        printf("%lld\n", counter);
    }
    
    return 0;
}
