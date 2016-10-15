// http://wcipeg.com/problem/P118EX4


#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << N << " X " << i << " = " << (i * N) << endl;
    }

    return 0;
}
