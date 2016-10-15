#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int y, m, d;
        cin >> y; cin >> m; cin >> d;
        
        if (  (2007 - y > 18) || (2007 - y == 18 && 2 - m > 0) || (2007 - y == 18 && 2 - m == 0 && 27 - d >= 0)  )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    
    return 0;
}
