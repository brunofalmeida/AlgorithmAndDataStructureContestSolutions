#include <iostream>
using namespace std;

int main () {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    
    if (a + b == c)
        cout << a << "+" << b << "=" << c << endl;
    else if (a - b == c)
        cout << a << "-" << b << "=" << c << endl;
    else if (a * b == c)
        cout << a << "*" << b << "=" << c << endl;
    else if (a / b == c)
        cout << a << "/" << b << "=" << c << endl;
    
    else if (a == b + c)
        cout << a << "=" << b << "+" << c << endl;
    else if (a == b - c)
        cout << a << "=" << b << "-" << c << endl;
    else if (a == b * c)
        cout << a << "=" << b << "*" << c << endl;
    else if (a == b / c)
        cout << a << "=" << b << "/" << c << endl;
    
    return 0;
}
