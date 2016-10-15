#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main()
{
    // input
    int N, M;
    cin >> N; cin >> M;
    
    vector< vector<int> > graph(N + 1); // adjacency list - use indices 1-N
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x; cin >> y;
        graph[x].push_back(y);
    }
    
    int p, q;
    cin >> p; cin >> q;
    
    
    
    
    // DFS - determine if p is taller than q
    
    // create flag and stack
    vector<bool> flag(N + 1, false);
    stack<int> s;
    s.push(p);
    
    // check each node
    while (s.size() > 0)
    {
        // pop and flag node
        int person = s.top();
        s.pop();
        flag[person] = true;
        
        if (person == q)
        {
            cout << "yes" << endl;
            return 0;
        }
    
        // add new nodes to stack
        for (int i = 0; i < graph[person].size(); i++)
        {
            if (! flag[ graph[person][i] ] )
                s.push( graph[person][i] );
        }
    }
    
    
    
    
    // DFS - determine if q is taller than p
    
    // create flag and stack
    vector<bool> flag2(N + 1, false);
    stack<int> s2;
    s2.push(q);
    
    // check each node
    while (s2.size() > 0)
    {
        // pop and flag node
        int person = s2.top();
        s2.pop();
        flag2[person] = true;
        
        if (person == p)
        {
            cout << "no" << endl;
            return 0;
        }
        
        // add new nodes to stack
        for (int i = 0; i < graph[person].size(); i++)
        {
            if (! flag2[ graph[person][i] ] )
                s2.push( graph[person][i] );
        }
    }
    
    
    
    
    // if p and q are not connected
    cout << "unknown" << endl;
    return 0;
}
