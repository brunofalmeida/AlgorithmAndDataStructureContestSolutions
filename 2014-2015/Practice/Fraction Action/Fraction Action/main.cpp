#include <iostream>

using namespace std;


int GCD(int a, int b)
{
    if (a == 1 or b == 1)
        return 1;
    else if (a < b)
        return GCD(a, b - a);
    else if (a > b)
        return GCD(a - b, b);
    else
        return a;
}


int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    
    
    if (a == 0)
    {
        cout << 0 << endl;
    }
    
    else if (a < b)
    {
        int gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;
        
        cout << a << "/" << b << endl;
    }
    
    else
    {
        int gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;
        
        if (b == 1)
            cout << a << endl;
        else
            cout << (a / b) << " " << (a % b) << "/" << (b) << endl;
    }
    
    return 0;
}
