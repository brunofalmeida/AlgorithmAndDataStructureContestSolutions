#include <iostream>
#include <vector>

using namespace std;

int N;              // number of card hands
vector<int> states; // possible results

vector<int> recurse(vector<int> oldCards) {
    vector<int> newCards;
    
    if (oldCards.size() == 1) {
        states.push_back(oldCards[0]);
    } else {
        
        for (int i1 = 0; i1 < oldCards.size() - 1; i1++) {
            for (int i2 = i1 + 1; i2 < oldCards.size(); i2++) {
                int num1 = oldCards[i1];
                int num2 = oldCards[i2];
                
                newCards.clear();
                for (int iNew = 0; iNew < oldCards.size(); iNew++) {
                    if (iNew != i1 && iNew != i2) {
                        newCards.push_back(oldCards[iNew]);
                    }
                }
                newCards.push_back(0);
                
                int iLast = (int)newCards.size() - 1;
                
                
                newCards[iLast] = num1 + num2;
                recurse(newCards);
                
                newCards[iLast] = num1 - num2;
                recurse(newCards);
                
                newCards[iLast] = num2 - num1;
                recurse(newCards);
                
                newCards[iLast] = num1 * num2;
                recurse(newCards);
                
                if (num2 != 0 && num1 % num2 == 0) {
                    newCards[iLast] = num1 / num2;
                    recurse(newCards);
                }
                
                if (num1 != 0 && num2 % num1 == 0) {
                    newCards[iLast] = num2 / num1;
                    recurse(newCards);
                }
            }
        }
    }
    
    return newCards;
}

int main() {
    cin >> N;
    
    vector<int> cards(4);
    
    for (int i = 0; i < N; i++) {
        for (int i2 = 0; i2 < 4; i2++) {
            cin >> cards[i2];
        }
        
        states.clear();
        recurse(cards);
        
        int maxNum = 0;
        for (int num : states) {
            if (num > maxNum && num <= 24) {
                maxNum = num;
            }
        }
        
        cout << maxNum << endl;
    }
    
    return 0;
}
