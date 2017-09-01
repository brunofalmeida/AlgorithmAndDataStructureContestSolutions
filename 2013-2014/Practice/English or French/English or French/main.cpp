#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main () {
    int N, s = 0, t = 0;
    string input, line;
    
    getline (cin, input);
    N = atoi (input.c_str());
    for (int i = 0; i < N; i++) {
        getline (cin, line);
        s += count (line.begin (), line.end (), 's') + count (line.begin (), line.end (), 'S');
        t += count (line.begin (), line.end (), 't') + count (line.begin (), line.end (), 'T');
    }
    
    if (t > s)
        cout << "English" << endl;
    else
        cout << "French" << endl;
    
    return 0;
}
