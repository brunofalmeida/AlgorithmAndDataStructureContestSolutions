#include <iostream>
#include <vector>
#include <utility>

using namespace std;


struct Space {
    int row;
    int col;
};


int N;  // number of rows
int M;  // number of data spaces required

vector<Space> required;


bool doSubPyramidsOverlap(Space first, Space second) {
    int firstMaxCol = first.col + (N - first.row);
    int firstMinCol = first.col - (N - first.row);
    
    int secondMaxCol = second.col + (N - second.row);
    int secondMinCol = second.col - (N - second.row);
    
    if (secondMinCol <= firstMaxCol || firstMinCol <= secondMaxCol)
        return true;
    else
        return false;
}


int main() {

    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        
        required.push_back(Space {r, c});
    }
    
    return 0;
}
