#include <iostream>
#include <map>

using namespace std;

int main() {
    // File
    freopen("learning.in", "r", stdin);
    freopen("learning.out", "w", stdout);
    
    
    // Input
    int N;      // number of existing cows
    int A, B;   // number of new cows
    cin >> N; cin >> A; cin >> B;
    
    map<int, bool> cows;    // weight, has spots
    for (int i = 0; i < N; i++) {
        string spots;
        int weight;
        cin >> spots; cin >> weight;
        if (spots == "S")
            cows[weight] = true;
        else
            cows[weight] = false;
    }
    
    
    // Algorithm
    int counter = 0;
    map<int, bool>::iterator it1 = cows.begin();
    map<int, bool>::iterator it2 = next(it1);
    
    
    // before list
    if (A < it1->first and it1->second)
        counter += it1->first - A;
    
    
    // within list
    while (it2 != cows.end()) {
        // all weights within it1 and it2 in range
        if (A <= it1->first and it2->first - 1 <= B) {
            if ( (it1->first + it2->first) % 2 == 0) {  // middle cow exists
                if (it1->second)
                    counter += (it2->first - it1->first) / 2;
                if (it2->second)
                    counter += (it2->first - it1->first) / 2 - 1;
                if (it1->second or it2->second)
                    counter++;
            }
            
            else {                                      // perfectly divided
                if (it1->second)
                    counter += (it2->first - it1->first + 1) / 2;
                if (it2->second)
                    counter += (it2->first - it1->first - 1) / 2;
            }
        }
        
        // some weights within it1 and it2 in range
        else if ( (it1->first <= A <= it2->first - 1) or (it1->first <= B <= it2->first - 1) ) {
            for (int i = it1->first; i <= it2->first - 1; i++) {
                if (A <= i <= B) {
                    if (i - it1->first < it2->first - i and it1->second)        // closer to it1
                        counter++;
                    else if (i - it1->first > it2->first - i and it2->second)   // closer to it2
                        counter++;
                    else if ( (i - it1->first == it2->first - i) and (it1->second or it2->second) ) // in middle
                        counter++;
                }
            }
        }
        
        it1++;
        it2++;
    }
    
    
    // after list
    if (it1->first <= B and it1->second)
        counter += B - it1->first + 1;
    
    
    // Output
    cout << counter << endl;
    
    
    return 0;
}
