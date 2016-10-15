#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N;    // number of people to infect
    long long K;          // spreading factor
    long long D;          // number of days
    
    cin >> N >> K >> D;
    
    
    long long leftToInfect = N;
    long long patientZeros = 0;
    
    for (long long day = 0; day <= D;) {
        long long expFunc = pow(K, D - day);
        long long patients = leftToInfect / expFunc;
                
        patientZeros += patients;
        leftToInfect -= patients * expFunc;
        
        if (leftToInfect == 0) {
            break;
        } else {
            long long daysLeft = (long long) ( log2(leftToInfect) / log2(K) );
            
            day = D - daysLeft;
        }
    }
    
    cout << patientZeros << endl;
    
    return 0;
}
