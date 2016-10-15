#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector< vector<int> > stacks(N + 1);
    
    
    for (int i = 1; i <= N; i++)    // for each step
    {
        char operation;
        int v;
        cin >> operation; cin >> v;
        stacks[i] = stacks[v];
        
        
        if (operation == 'a')
        {
            stacks[i].push_back(i);
        }
        
        else if (operation == 'b')
        {
            cout << stacks[i].back();
            stacks[i].pop_back();
        }
        
        else if (operation == 'c')
        {
            int w;
            cin >> w;
            int counter = 0;
            
            for (int i1 = 0; i1 < stacks[i].size(); i1++)   // index of first list (i)
            {
                if ( find(stacks[w].begin(), stacks[w].end(), stacks[i][i1]) != stacks[w].end() )
                    counter++;
            }
            
            cout << counter << endl;
        }
    }
    
    
    return 0;
}