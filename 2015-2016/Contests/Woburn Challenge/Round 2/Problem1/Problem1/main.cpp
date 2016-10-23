#include <iostream>
#include <algorithm>

using namespace std;

int N;
int scenes[10000];

bool recurse() {
    if (find(scenes, scenes + N, 0) == scenes + N) {
        return true;
    }
    
    else {
        for (int i = 0; i < N; i++) {
            if (scenes[i] == 0) {
                for (int setting = 1; setting <= 4; setting++) {
                    
                    if (!(i - 1 >= 0 && scenes[i - 1] == setting) &&
                        !(i + 1 < N && scenes[i + 1] == setting)) {
                        
                        scenes[i] = setting;
                        if (recurse()) {
                            return true;
                        }
                        scenes[i] = 0;
                    }
                }
            }
        }
        
        return false;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> scenes[i];
    }
    
    recurse();
    
    for (int i = 0; i < N; i++) {
        cout << scenes[i];
    }
    cout << endl;
    
    return 0;
}
