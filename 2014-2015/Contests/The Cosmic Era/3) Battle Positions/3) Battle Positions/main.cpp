#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct Range {
    int first;
    int last;
    int needed;
};

inline bool operator<(const Range& left, const Range& right) {
    return left.first < right.first or (left.first == right.first and left.last < right.last);
}
inline bool operator>(const Range& left, const Range& right) {
    return left.first > right.first or (left.first == right.first and left.last > right.last);
}
inline bool operator==(const Range& left, const Range& right) {
    return left.first == right.first and left.last == right.last;
}

int main() {
    int I;  // number of stations
    int N;  // number of troops required per station
    int J;  // number of waves of troops
    
    scanf("%d", &I);
    scanf("%d", &N);
    scanf("%d", &J);
    
    set<Range> insecure = {Range{1, I, N}};
    
    for (int i = 0; i < J; i++) {
        int Xi, Xf, K;  // start, end, number of troops
        scanf("%d %d %d", &Xi, &Xf, &K);
        
        for (set<Range>::iterator it = insecure.begin(); it != insecure.end();) {
            Range range = *it;
            
            if (Xi <= range.last and range.first <= Xf) {
                if (range.first < Xi)
                    insecure.insert(Range{range.first, Xi - 1, range.needed});
                if (Xf < range.last)
                    insecure.insert(Range{Xf + 1, range.last, range.needed});
                if (K < range.needed)
                    insecure.insert(Range{max(range.first, Xi), min(range.last, Xf), range.needed - K});
                it = insecure.erase(it);
            }
            else {
                it++;
            }
        }
    }
    
    int total = 0;
    for (set<Range>::iterator it = insecure.begin(); it != insecure.end(); it++)
        total += it->last - it->first + 1;
    printf("%d\n", total);
    
    return 0;
}
