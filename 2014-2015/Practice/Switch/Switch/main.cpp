#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


// switches off consecutive light blocks of 4 or more
void update(vector<bool>& lights)
{
    int streak = 0;     // number of previous consecutive lights on
    
    for (int i = 0; i < lights.size(); i++)
    {
        if (lights[i])
        {
            streak++;
        }
        
        else
        {
            if (streak >= 4)        // 4 or more consecutive trues
            {
                for (int ii = i - streak; ii < i; ii++)
                    lights[ii] = false;
            }
            
            streak = 0;
        }
    }
    
    // necessary if last item is true
    if (streak >= 4)        // 4 or more consecutive trues
    {
        for (int ii = lights.size() - streak; ii < lights.size(); ii++)
            lights[ii] = false;
    }
}


int main()
{
    // input
    int K;
    cin >> K;
    vector<bool> lights(K);
    
    for (int i = 0; i < K; i++)
    {
        int input;
        cin >> input;
        lights[i] = (bool)input;
    }
    
    // make queue and flag
    queue< pair< vector<bool>, int > > q;
    q.push( pair< vector<bool>, int > (lights, 0) );
    set< vector<bool> > flag;
    
    // search
    while (q.size() > 0)
    {
        // pop and update flag
        vector<bool> lights(q.front().first);
        int numChanges = q.front().second;
        q.pop();
        flag.insert(lights);
        
        // find and replace consecutive sequences
        update(lights);
        
        // add new states to queue
        for (int i = 0; i < lights.size(); i++)
        {
            if ( !lights[i] )
            {
                vector<bool> lightsNew(lights);
                lightsNew[i] = true;
                if ( flag.find(lightsNew) == flag.end() )
                    q.push( pair< vector<bool>, int > (lightsNew, numChanges + 1) );
            }
        }
        
        // check if all values are false
        if ( find(lights.begin(), lights.end(), true) == lights.end() )
        {
            cout << numChanges << endl;
            break;
        }
    }
    
    return 0;
}
