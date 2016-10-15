#include <iostream>

#define MOD 1000000007

using namespace std;

int prereqs[100001];
bool learned[100001] = {false};
int perms[100001] = {-1};

int N;  // number of abilities

long long perm(int remaining){
    if (remaining == 1) {
        return 1;
    }
    
    long long sum=0;
    
    for (int i=1;i<=N;i++){
        if (learned[i] == false and learned[prereqs[i]]) {
            
            if (perms[i] == -1) {
                learned[i] = true;
                perms[i] = perm(remaining - 1) % MOD;
                learned[i] = false;
            }
            
            sum += perms[i];
        }
    }
    
    return sum;
}

int main() {
    learned[0] = true;
    
    cin>>N;
    
    for (int i = 1; i <= N; i++) {
        cin >> prereqs[i];
    }
    
    long long total=0;
    
    for (int i=1;i<=N;i++){
        if (!prereqs[i]){
            learned[i]=true;
            total+=perm(N-1)%MOD;
            learned[i]=false;
        }
    }
    
    cout<<total<<endl;
    
    return 0;
}
