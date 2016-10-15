#include <iostream>

using namespace std;

bool pal(string str) {
    if (str.length() == 0 || str.length() == 1)
        return true;
    else if (str[0] == str[str.length() - 1])
        return pal(str.substr(1, str.length() - 2));
    else
        return false;
}

int main() {
    cout << pal("hello") << endl;
    cout << pal("alula") << endl;
    cout << pal("anna") << endl;
    cout << pal("programmer") << endl;
    
    return 0;
}
