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







//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N;
//int targets[5];
//int spinner[5000];
//
//int main() {
//    freopen("DATA21.txt", "r", stdin);
//    
//    for (int i = 0; i < 10; i++) {
//        cin >> N;
//        
//        for (int n = 0; n < N; n++) {
//            cin >> spinner[n];
//        }
//        
//        
//        for (int t = 0; t < 5; t++) {
//            cin >> targets[t];
//        }
//        
//        for (int t = 0; t < 5; t++) {
//            int target = targets[t];
//            
//            bool possible = false;
//            
//            for (int i1 = 0; i1 < N; i1++) {
//                int spin1 = spinner[i1];
//                
//                for (int i2 = 0; i2 < N; i2++) {
//                    int spin2 = spinner[i2];
//                    
//                    for (int i3 = 0; i3 < N; i3++) {
//                        int spin3 = spinner[i3];
//                        
//                        if ((spin1 + spin2) + spin3 == target) {
//                            possible = true;
//                            break;
//                        } else if ((spin1 + spin2) * spin3 == target) {
//                            possible = true;
//                            break;
//                        } else if ((spin1 * spin2) + spin3 == target) {
//                            possible = true;
//                            break;
//                        } else if ((spin1 * spin2) * spin3 == target) {
//                            possible = true;
//                            break;
//                        }
//                    }
//                    
//                    if (possible) {
//                        break;
//                    }
//                }
//                
//                if (possible) {
//                    break;
//                }
//            }
//            
//            if (possible) {
//                cout << "T";
//            } else {
//                cout << "F";
//            }
//        }
//        
//        cout << endl;
//    }
//    
//    return 0;
//}
