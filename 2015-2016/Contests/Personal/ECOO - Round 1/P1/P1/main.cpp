#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int wt,wa,wp,wq;
int a,b,c,d;
int sum;
int n;
int numPass;

int main() {
    freopen("DATA12.txt","r",stdin);
    
    
    for (int tc=0; tc < 10; tc++){
        numPass = 0;

        cin >> wt >> wa >> wp >> wq >> n;
        
        for (int i = 0; i < n; i++) {
            
            sum = 0;
            cin >> a >> b >> c >> d;
            sum = (a*wt)+(b*wa)+(c*wp)+(d*wq);
            if (sum >= 5000)
                numPass++;
        }
        cout << numPass << endl;
    }
    
    return 0;
}
