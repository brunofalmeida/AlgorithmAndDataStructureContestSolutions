#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;   // number of tests
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;   // number of cars
        
        stack<int> top;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            top.push(num);
        }
        
        stack<int> branch;
        
        int nextNum = 1;
        
        while (true) {
            if (nextNum > N) {
                cout << "Y" << endl;
                break;
            }
            else if (top.size() > 0 and top.top() == nextNum) {
                top.pop();
                nextNum++;
            }
            else if (branch.size() > 0 and branch.top() == nextNum) {
                branch.pop();
                nextNum++;
            }
            else if (top.size() > 0) {
                branch.push(top.top());
                top.pop();
            }
            else {
                cout << "N" << endl;
                break;
            }
        }
    }
    
    return 0;
}
