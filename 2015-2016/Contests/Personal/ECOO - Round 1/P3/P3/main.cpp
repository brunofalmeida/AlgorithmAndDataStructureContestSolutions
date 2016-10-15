#include <iostream>

using namespace std;


int main() {
    freopen("DATA31.txt","r",stdin);
    
    int n, input, sum;
    int iSecondLowest;
    
    for (int tc = 0; tc < 10; tc++) {
        cin >> n;
        int index[n+1];
        sum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> input;
            index[input] = i;
        }
        
        for (int i = n; i > 1; i--) {
            iSecondLowest = index[i-1];
            
            if (iSecondLowest > index[i]) {
                sum += iSecondLowest;

                for (int j = 1; j <= n; j++) {
                   if (index[j] < iSecondLowest) //update all before
                       index[j]++;
                }
                index[i-1]=0;
            }
        }
        cout << sum << endl;
    }
    
    return 0;
}
