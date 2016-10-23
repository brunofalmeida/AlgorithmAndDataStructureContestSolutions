//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//string words[100000];
//
//int main() {
//    int N;  // end number
//    int M;  // number of known words
//    cin >> N >> M;
//    
//    int firstFizz = -1; // 3
//    int firstBuzz = -1; // 5
//    int firstFizzBuzz = -1; // 3 and 5
//    
//    for (int i = 0; i < M; i++) {
//        cin >> words[i];
//        
//        if (words[i] == "fizz" && firstFizz == -1) {
//            firstFizz = i;
//        }
//        if (words[i] == "buzz" && firstBuzz == -1) {
//            firstBuzz = i;
//        }
//        if (words[i] == "fizzbuzz" && firstFizzBuzz == -1) {
//            firstFizzBuzz = i;
//        }
//    }
//    
//    bool done = false;
//    
//    if (firstFizzBuzz != -1) {
//        for (int i = firstFizzBuzz; i < M; i += 15) {
//            if (words[i] != "fizzbuzz") {
//                cout << 0 << endl;
//                done = true;
//                break;
//            }
//        }
//    }
//    
//    if (!done && firstBuzz != -1) {
//        for (int i = firstBuzz; i < M; i += 5) {
//            if (!(words[i] == "buzz" || words[i] == "fizzbuzz")) {
//                cout << 0 << endl;
//                done = true;
//                break;
//            }
//        }
//    }
//    
//    if (!done && firstFizz != -1) {
//        for (int i = firstFizz; i < M; i += 3) {
//            if (!(words[i] == "fizz" || words[i] == "fizzbuzz")) {
//                cout << 0 << endl;
//                done = true;
//                break;
//            }
//        }
//    }
//    
//    if (!done) {
//        if (firstFizzBuzz != -1) {
//            int minIndex = 14;
//            int maxIndex = ((N / 15) * 15) - 1;
//            
//            int times = (maxIndex - minIndex) / 15 + 1;
//            
//            cout << times << endl;
//        } else if (firstBuzz != -1) {
//            int minIndex = 4;
//            int maxIndex = ((N / 5) * 5) - 1;
//            
//            int times = (maxIndex - minIndex) / 5 + 1;
//            
//            cout << times << endl;
//        } else if (firstFizz != -1) {
//            int minIndex = 2;
//            int maxIndex = ((N / 3) * 3) - 1;
//            
//            int times = (maxIndex - minIndex) / 3 + 1;
//            
//            cout << times << endl;
//        }
//    }
//    
//    return 0;
//}









#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string a;
string b;

int main () {
    
    

    int n,m;
    string input;
    cin >> n >> m;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        if (i%15 == 0)
            a = a + "4";
        else if (i%5 == 0)
            a = a +"3";
        else if (i%3 == 0)
            a = a+"2";
        else
            a = a + "1";
    }
    for (int i = 1; i <= m; i++) {
        cin >> input;
        if (input == "ook")
            b = b+"1";
        else if (input == "fizz")
            b = b+"2";
        else if (input == "buzz")
            b = b+"3";
        else
            b = b +"4";
    }
    int start = 0;
    int output = 0;
    for (int i = 0 ; i < a.length()-b.length(); i++) {
        if (a.substr(i,b.length()) == b)
            output++;
    }
    cout << output;
}
/*string known(100000, ' ');
string sequence = "112132112312114";

int main() {
    int N;  // end number
    int M;  // number of known words
    cin >> N >> M;

    string word;
    for (int i = 0; i < M; i++) {
        cin >> word;
        
        if (word == "ook") {
            known[i] = '1';
        } else if (word == "fizz") {
            known[i] = '2';
        } else if (word == "buzz") {
            known[i] = '3';
        } else if (word == "fizzbuzz") {
            known[i] = '4';
        }
    }
    
    bool none = false;
    
    int iSequenceInKnown = (int) known.find(sequence);
    
    if (iSequenceInKnown != string::npos) {
        int knownNumExtraBeginning = iSequenceInKnown;
        int knownNumFullSequences = (M - knownNumExtraBeginning) / 15;
        int knownNumExtraEnd = M - (knownNumFullSequences * 15) - knownNumExtraBeginning;
        
        int iSequenceStart = 15 - knownNumExtraBeginning;
        int iSequenceEnd = knownNumExtraEnd;
        
        if (known.substr(0, knownNumExtraBeginning) != sequence.substr(iSequenceStart)) {
            none = true;
        }
        if (!none && known.substr(M - knownNumExtraEnd) != sequence.substr(0, iSequenceEnd)) {
            none = true;
        }
        if (!none) {
            for (int iFullSequence = 0; iFullSequence < knownNumFullSequences; iFullSequence++) {
                if (known.substr(knownNumExtraBeginning + (iFullSequence * 15), 15) != sequence) {
                    none = true;
                    break;
                }
            }
        }
    }
    
    if (none) {
        cout << 0 << endl;
    }

    return 0;
} */
