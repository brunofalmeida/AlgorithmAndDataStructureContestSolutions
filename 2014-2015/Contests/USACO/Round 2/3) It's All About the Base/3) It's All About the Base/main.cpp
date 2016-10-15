#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int baseNToBase10(string baseN, int base) {
    int base10 = 0;
    
    for (int i = baseN.length() - 1, factor = 1; i >= 0; i--, factor *= base)
        base10 += (baseN[i] - 48) * factor;
    
    return base10;
}

string base10ToBaseN(int base10, int base) {
    string baseN = "";
    
    for (int exp = 2; exp >= 0; exp--) {
        int digit = base10 / pow(base, exp);
        base10 -= digit * pow(base, exp);
        
        if (1 <= digit and digit <= 9)
            baseN += (char)(digit + 48);
        else if (digit < 1)
            baseN += "/";
        else if (digit > 9)
            baseN += ":";
    }
    
    return baseN;
}


int main() {
    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);
    
    int K;
    scanf("%d", &K);
    
    for (int k = 0; k < K; k++) {
        int nx, ny;
        scanf("%d %d", &nx, &ny);
        string NX = to_string(nx), NY = to_string(ny);
        
        for (int base1 = 10; base1 <= 15000; base1++) {
            int base10 = baseNToBase10(NX, base1);
            
            bool isDone = false;
            int base2Low = 10;
            int base2High = 15000;
            if (NX < NY)
                base2High = base1;
            else if (NX > NY)
                base2Low = base1;
            
            while (true) {
                int base2Mid = (base2Low + base2High) / 2;
                string baseN = base10ToBaseN(base10, base2Mid);
                
                if (baseN == NY) {
                    cout << base1 << " " << base2Mid << endl;
                    isDone = true;
                    break;
                }
                else if (base2Low == base2High) {
                    break;
                }
                else if (baseN < NY) {
                    base2High = base2Mid;
                }
                else if (baseN > NY) {
                    base2Low = base2Mid + 1;
                }
                
                
            }
            
            if (isDone)
                break;
        }
    }
    
    return 0;
}
