#include <iostream>
using namespace std;

void count_down(int i) {
    cout << i << endl;
    if (i == 0) return ;
    count_down(i - 1);
}
int main() {
    int N;
    cin >> N ;
    cout << "counting down ..." << endl;
    count_down(N);
}
