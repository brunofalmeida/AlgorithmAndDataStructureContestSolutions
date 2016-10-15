#include <iostream>
using namespace std;

int pow(int a, int b) {
    if (b == 0)
        return 1;
    else
        return a * pow(a, b - 1);
}

int main() {
    cout << pow(2, 1) << endl;
    cout << pow(3, 2) << endl;
    cout << pow(5, 3) << endl;
}
