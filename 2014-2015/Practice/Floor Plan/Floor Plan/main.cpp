#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

//#define TEST

using namespace std;


#ifdef TEST
    #include <fstream>
    #define INPUT file
    ifstream file("/Users/Bruno/Google Drive/Grade 11/Extra-Curriculars/Computer Science Club/WCIPEG/Floor Plan/Floor Plan/test.txt");
#endif

#ifndef TEST
    #define INPUT cin
#endif




int main()
{
    // input
    int flooring, r, c;
    INPUT >> flooring;
    INPUT >> r;
    INPUT >> c;
    
    vector< vector<bool> > grid(r);
    for (int i = 0; i < r; i++)
        grid[i].resize(c);
    
    for (int row = 0; row < r; row++)
    {
        string line;
        INPUT >> line;
        
        for (int col = 0; col < c; col++)
        {
            if (line[col] == '.')
                grid[row][col] = true;
            else
                grid[row][col] = false;
        }
    }
    
    
    // create list of rooms, flag matrix
    vector<int> rooms;
    vector< vector<bool> > flag(r, vector<bool> (c, false) );
    
    
    // DFS flood fill
    for (int row = 0; row < r; row++)   // start new room
    {
        for (int col = 0; col < c; col++)
        {
            if ( grid[row][col] && ! flag[row][col] )
            {
                // create stack, room size counter
                int counter = 0;    // number of spaces in room
                stack< pair<int, int> > s;
                s.push( pair<int, int> (row, col) );
                flag[row][col] = true;
                
                // for each space
                while (s.size() > 0)
                {
                    // pop node, mark as flag, increase counter
                    int y = s.top().first;
                    int x = s.top().second;
                    s.pop();
                    counter++;
                    
                    // add new nodes to stack
                    for (int yNext = y - 1; yNext <= y + 1; yNext++)
                    {
                        for (int xNext = x - 1; xNext <= x + 1; xNext++)
                        {
                            if ( 0 <= yNext && yNext < r && 0 <= xNext && xNext < c && grid[yNext][xNext] && ! flag[yNext][xNext] )
                            {
                                s.push( pair<int, int> (yNext, xNext) );
                                flag[yNext][xNext] = true;
                            }
                        }
                    }
                }
                
                rooms.push_back(counter);
            }
        }
    }
    
    
    // sort and output result
    sort( rooms.begin(), rooms.end() );
    reverse( rooms.begin(), rooms.end() );
    
    int sum = 0;
    for (int i = 0; i < rooms.size(); i++)
    {
        if ( flooring < sum + rooms[i] )
        {
            if (i == 1)
                cout << "1 room, ";
            else
                cout << i << " rooms, ";
            
            cout << flooring - sum << " square metre(s) left over" << endl;
            return 0;
        }
        
        sum += rooms[i];
    }
    
    if (sum <= flooring)
    {
        if (rooms.size() == 1)
            cout << "1 room, ";
        else
            cout << rooms.size() << " rooms, ";
        
        cout << flooring - sum << " square metre(s) left over" << endl;
    }
    
    
    return 0;
}
