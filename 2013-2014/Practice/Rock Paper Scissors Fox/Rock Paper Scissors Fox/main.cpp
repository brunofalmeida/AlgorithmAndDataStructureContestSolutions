#include <iostream>
using namespace std;

int main () {
    int N;
    string move;
    bool play = true;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> move;
        if (play) {
            if (move == "Scissors")
                cout << "Rock" << endl;
            else if (move == "Paper")
                cout << "Scissors" << endl;
            else if (move == "Rock")
                cout << "Paper" << endl;
            else if (move == "Fox")
                cout << "Foxen" << endl;
            else if (move == "Foxen")
                play = false;
        }
    }
    
    return 0;
}