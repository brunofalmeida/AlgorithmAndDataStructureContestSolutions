#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int targets[5];
int cnt[101];
bool poss[5];

int main() {
    freopen("DATA22.txt", "r", stdin);
    
    for (int i = 0; i < 10; i++) {
        memset(cnt, 0, sizeof cnt);
        
        cin >> N;
        
        for (int n = 0; n < N; n++) {
            int num;
            cin >> num;
            cnt[num] ++;
        }
        
        
        for (int t = 0; t < 5; t++) {
            cin >> targets[t];
            poss[t] = false;
            
            for (int i = 1; i <= 100 ; i++) {
                for (int j = 1; j <= 100; j ++) {
                    for (int k = 1; k <= 100; k ++)
                    {
                        if (cnt[i] > 0 && cnt[j] > 0 && cnt[k] > 0)
                        {
                            if ((i + j) + k == targets[t])
                                poss[t] = true;
                            if ((i + j) * k == targets[t])
                                poss[t] = true;
                            if (i * j + k == targets[t])
                                poss[t] = true;
                            if (i * j * k == targets[t])
                                poss[t] = true;
                        }
                    }
                }
            }
            
            if (poss[t]) {
                cout << "T";
            } else {
                cout << "F";
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
