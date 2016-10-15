#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    
    vector<char> directions;
    vector<string> locations;
    
    char direction_first;
    cin >> direction_first;
    
    while (true)
    {
        string location;
        cin >> location;
        if (location == "SCHOOL")
            break;
        else
            locations.push_back(location);
        
        char direction;
        cin >> direction;
        directions.push_back(direction);
    }
    
    
    for (int i = (int)locations.size() - 1; i >= 0; i--)
    {
        if (directions[i] == 'L')
            cout << "Turn RIGHT onto " << locations[i] << " street." << endl;
        else
            cout << "Turn LEFT onto " << locations[i] << " street." << endl;
    }
    
    if (direction_first == 'L')
        cout << "Turn RIGHT into your HOME." << endl;
    else
        cout << "Turn LEFT into your HOME." << endl;
    
    
    return 0;
}
