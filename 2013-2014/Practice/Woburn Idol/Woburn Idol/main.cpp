#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    string name;
    cin >> name;
    transform (name.begin (), name.end (), name.begin (), ::tolower);
    
    if (count (name.begin (), name.end (), 'a') >=
        count (name.begin (), name.end (), 'e') + count (name.begin (), name.end (), 'i') + count (name.begin (), name.end (), 'o') + count (name.begin (), name.end (), 'u'))
        cout << "Advance to next round" << endl;
    else
        cout << "Does not advance to next round" << endl;
    
    return 0;
}