#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // construct graph
    vector< vector<int> > graph(8); // adjacency list - only use indices 1-7
    
    graph[1].push_back(7);
    graph[1].push_back(4);
    graph[2].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    while (true)
    {
        int x, y;
        cin >> x;
        cin >> y;
        if (x == 0 and y == 0)
            break;
        graph[x].push_back(y);
    }
    
    
    // construct in-degree list
    vector<int> indegree(8, 0); // list of vertex in-degrees - only use indices 1-7
    for (int x = 1; x <= 7; x++)    // check each adjacency list
    {
        // increment each connected vertex
        for (int i = 0; i < graph[x].size(); i++)
            indegree[graph[x][i]]++;
    }
    
    
    // create remaining and final lists
    vector<int> remaining = {1, 2, 3, 4, 5, 6, 7};
    vector<int> chores;
    
    
    // topological sort
    bool repeat = true;
    while (remaining.size() > 0 and repeat)
    {
        repeat = false;
        
        for (int i = 0; i < remaining.size(); i++)  // check each remaining vertex
        {
            int x = remaining[i];
            
            if (indegree[x] == 0)   // if zero in-degree
            {
                // decrement in-degrees of connected vertices
                for (int ii = 0; ii < graph[x].size(); ii++)
                    indegree[graph[x][ii]]--;
                
                // update lists and repeat loop
                remaining.erase(remaining.begin() + i);
                chores.push_back(x);
                repeat = true;
                break;
            }
        }
    }
    
    
    // output list
    if (repeat)
    {
        for (int i = 0; i < 6; i++)
            cout << chores[i] << " ";
        cout << chores[6] << endl;
    }
    
    else
    {
        cout << "Cannot complete these tasks. Going to bed." << endl;
    }
    
    
    return 0;
}
