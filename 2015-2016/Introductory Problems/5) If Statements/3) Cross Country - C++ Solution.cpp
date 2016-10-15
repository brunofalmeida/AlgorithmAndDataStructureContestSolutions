#include <iostream>
using namespace std;

int main() {
    // Create a variable and input the two letter code
    string code;
    cin >> code;
    
    
    /*
     Go through an if/else if/else chain to output the appropriate message
     Only one of the following bodies (indented code blocks between curly braces) will execute
    
     The first true condition will run its body and output the appropriate message,
     then skip the rest of the conditions
     If none of the conditions are true, the body of the else block will run
     and print "invalid code"
     
     Spelling and capitalization counts!
     */
    if (code == "MG") {
        cout << "midget girls" << endl;
    }
    else if (code == "MB") {
        cout << "midget boys" << endl;
    }
    else if (code == "JG") {
        cout << "junior girls" << endl;
    }
    else if (code == "JB") {
        cout << "junior boys" << endl;
    }
    else if (code == "SG") {
        cout << "senior girls" << endl;
    }
    else if (code == "SB") {
        cout << "senior boys" << endl;
    }
    else {
        cout << "invalid code" << endl;
    }
	
    return 0;
}
