#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // input
    int M;  // max group size
    cin >> M;
    int Q;  // length of queue
    cin >> Q;
    
    vector<string> names;
    vector<int> times;
    for (int i = 0; i < Q; i++)
    {
        cin >> names[i];
        cin >> times[i];
    }
    
    
    // DP
    vector< vector< vector<int> > > dpNames(Q + 1);
    vector<int> dpTime(Q + 1);

    
    return 0;
}
