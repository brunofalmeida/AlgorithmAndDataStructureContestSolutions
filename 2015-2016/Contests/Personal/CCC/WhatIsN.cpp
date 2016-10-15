#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int num = n / 2 + 1;

    if (n > 5) {
        num -= (n - 5);
    }

    cout << num << endl;

    return 0;
}
