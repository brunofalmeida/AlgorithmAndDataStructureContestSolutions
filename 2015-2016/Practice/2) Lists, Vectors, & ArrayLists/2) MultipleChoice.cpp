// http://wcipeg.com/problem/ccc11s2


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<char> student(N);
    for (int i = 0; i < N; i++) {
        cin >> student[i];
    }
    
    vector<char> correct(N);
    for (int i = 0; i < N; i++) {
        cin >> correct[i];
    }
    
    int numCorrect = 0;
    for (int i = 0; i < N; i++) {
        if (student[i] == correct[i]) {
            numCorrect++;
        }
    }
    
    cout << numCorrect << endl;
    
    return 0;
}
