#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // input
    int N;
    cin >> N;
    
    vector< pair<int, int> > points(N);
    for (int i = 0; i < N; i++)
    {
        cin >> points[i].first; cin >> points[i].second;
    }
    
    
    for (int i1 = 0; i1 < N; i1++) // for each contestant
    {
        // algorithm
        int bestPlace = 1;
        int worstPlace = 1;
        
        for (int i2 = 0; i2 < N; i2++)  // for each other contestant, check for first contestant losses
        {
            if (i1 != i2)
            {
                if ( (points[i1].first < points[i2].first) and
                    (points[i1].second < points[i2].second) )
                {
                    bestPlace++;
                    worstPlace++;
                }
                
                else if (not ( (points[i1].first > points[i2].first) and
                              (points[i1].second > points[i2].second) ))
                {
                    // best case
                    if ( (points[i1].first + points[i1].second + 650) <
                        (points[i2].first + points[i2].second) )
                        bestPlace++;
                    
                    // worst case
                    if ( (points[i1].first + points[i1].second) <
                        (points[i2].first + points[i2].second + 650) )
                        worstPlace++;
                }
            }
        }
        
        
        // output
        cout << bestPlace << " " << worstPlace << endl;
    }
    
    
    return 0;
}
