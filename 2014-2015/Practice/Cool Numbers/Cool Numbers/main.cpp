#include <iostream>
#include <cmath>

using namespace std;

bool is_int(double n)
{
    if ( n == int(n) )
        return true;
    else
        return false;
}

int main ()
{
    int a, b;
    int counter = 0;
    
    cin >> a;
    cin >> b;
    
    int cb_root_a = cbrt(a);
    int cb_root_b = int(cbrt(b) ) + 1;
    
    for (int i = cb_root_a; i <= cb_root_b; i++)
    {
        if ( is_int( pow(i, 1.5) ) && pow(i, 3) >= a && pow(i, 3) <= b )
            counter++;
    }
    
    cout << counter << endl;
    
    return 0;
}