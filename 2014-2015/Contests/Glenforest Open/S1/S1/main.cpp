#include <iostream>

using namespace std;

int main()
{
    // input
    int N;
    cin >> N;
    
    pair<int, long long> p1(0, 0); // person number, points
    pair<int, long long> p2(0, 0);
    pair<int, long long> p3(0, 0);
    
    
    for (int i = 1; i <= N; i++)
    {
        // test case input
        int T;
        cin >> T;
        
        long long product = 1;
        for (int ii = 0; ii < T; ii++)
        {
            int n;
            cin >> n;
            product *= n;
        }
        
        
        // algorithm
        if (product >= p1.second)
        {
            p3 = make_pair(p2.first, p2.second);
            p2 = make_pair(p1.first, p1.second);
            p1 = make_pair(i, product);
        }
        
        else if (product >= p2.second)
        {
            p3 = make_pair(p2.first, p2.second);
            p2 = make_pair(i, product);
        }
        
        else if (product >= p3.second)
        {
            p3 = make_pair(i, product);
        }
    }
    
    
    // output
    cout << p1.first << '\n';
    cout << p2.first << '\n';
    cout << p3.first << '\n';
    
    
    return 0;
}
