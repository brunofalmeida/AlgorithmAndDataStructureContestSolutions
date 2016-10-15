#include <iostream>
#include <vector>

using namespace std;


// each person moving
struct person
{
    string name;
    int from;
    int to;
};


int main()
{
    // input
    int n;
    cin >> n;
    
    vector<person> people;  // list of people moving
    vector<bool> occupied(101, false); // only use indices 1-100 - true if someone is living in that house
    
    for (int i = 0; i < n; i++)     // input each person
    {
        person p;
        cin >> p.name;
        cin >> p.from;
        cin >> p.to;
        
        people.push_back(p);
        occupied[p.from] = true;
    }
    
    
    // topological sort
    vector<string> moveOrder;   // list of names in order
    bool repeat = true;     // can continue search
    
    while (people.size() > 0 and repeat)
    {
        repeat = false;
        
        for (int i = 0; i < people.size(); i++)     // go through list of people
        {
            if ( ! occupied[people[i].to] )     // if person can move
            {
                moveOrder.push_back(people[i].name);
                
                occupied[people[i].from] = false;
                occupied[people[i].to] = true;
                people.erase(people.begin() + i);
                
                repeat = true;
            }
        }
    }
    
    
    // output
    if (repeat)
    {
        for (int i = 0; i < moveOrder.size(); i++)
            cout << moveOrder[i] << endl;
    }
    
    else
    {
        cout << "Impossible" << endl;
    }
    
    
    return 0;
}
