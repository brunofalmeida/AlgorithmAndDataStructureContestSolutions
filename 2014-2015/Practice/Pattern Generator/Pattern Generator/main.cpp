#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* recursion
* returns list of bit patterns in descending order
*/
vector<string> recurse(int n, int k)
{
    if (k == 0)
    {
        return vector<string> {string(n, '0')};
    }
    
    else if (n == k)
    {
        return vector<string> {string(n, '1')};
    }
    
    else    // n > 1 and k > 0
    {
        vector<string> list;
        
        vector<string> list1 = recurse(n - 1, k - 1);
        for (int i = 0; i < list1.size(); i++)
            list.push_back("1" + list1[i]);
        
        vector<string> list2 = recurse(n - 1, k);
        for (int i = 0; i < list2.size(); i++)
            list.push_back("0" + list2[i]);
        
        return list;
    }
}


int main()
{
    // input
    int numPairs;
    cin >> numPairs;
    
    
    // for each set of bit patterns
    for (int i = 0; i < numPairs; i++)
    {
        // input
        int n, k;
        cin >> n; cin >> k;
        
        
        // recursion
        vector<string> list = recurse(n, k);
        
        
        // output
        cout << "The bit patterns are" << endl;
        
        for (int i = 0; i < list.size(); i++)
            cout << list[i] << endl;
        
        if (i < numPairs - 1)
            cout << endl;
    }
    
    
    return 0;
}
