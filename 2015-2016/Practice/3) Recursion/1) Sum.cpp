#include <iostream>
using namespace std;

int sum(int n) {
    if (n <= 1)
        return 1;
    else
        return n + sum(n - 1);
}

int main() {
    cout << sum(1) << endl;
    cout << sum(2) << endl;
    cout << sum(3) << endl;
    cout << sum(4) << endl;
    cout << sum(5) << endl;
}
