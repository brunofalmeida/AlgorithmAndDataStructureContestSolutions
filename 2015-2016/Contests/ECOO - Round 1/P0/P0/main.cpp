#include <iostream>

using namespace std;

int main() {
    freopen("DATA01.txt", "r", stdin);
    
    for (int tc = 0; tc < 5; tc++) {
        int N;
        cin >> N;
        
        string line;
        cin >> line;
        
        int last = 0;
        int good = true;
        
        for (int i = 0; i < N; i++) {
            int current = (int) (line[i]);
            
            if ('a' <= current && current <= 'z') {
                current -= ('a' - 'A');
            }
            
            if (last > current) {
                good = false;
            }
            
            last = current;
        }
        
        cout << N << " ";
        if (good) {
            cout << "IN ORDER";
        } else {
            cout << "NOT IN ORDER";
        }
        cout << endl;
    }
    
    return 0;
}
