#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // input
    int N;  // number of people
    int M;  // number of TV channels
    int P;  // initial channel
    cin >> N; cin >> M; cin >> P;
    
    vector<int> people(N + 1); // favourite channel for each person - do not use 0
    vector< vector<int> > hatedChannels(M + 1);    // list of hating people for each channel - do not use 0
    
    for (int i = 1; i <= N; i++) // for each person
    {
        int a;  // favourite channel
        int b;  // hated channel
        cin >> a; cin >> b;
        
        people[i] = a;
        hatedChannels[b].push_back(i);
    }
    
    
    // search
    int channel = P;
    int numChanges = 0;
    
    do
    {
        if (hatedChannels[channel].size() > 0)
        {
            channel = people[ hatedChannels[channel][0] ];
            numChanges++;
        }
        
        else
        {
            break;
        }
    }
    while (channel != P);
    
    
    // output
    if (channel == P and numChanges > 0)
        cout << -1 << endl;
    else
        cout << numChanges << endl;
    
    
    return 0;
}
