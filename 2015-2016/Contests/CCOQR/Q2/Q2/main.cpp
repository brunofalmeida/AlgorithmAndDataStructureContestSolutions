//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//#define N_MAX 100001
//
//using namespace std;
//
//
//vector<int> connections[N_MAX];
//
//
//int main() {
//    int N;      // number of rooms
//    cin >> N;
//    
//    // for each room (i)
//    for (int i = 1; i <= N; i++) {
//        int k;  // number of corridors connecting to room i
//        cin >> k;
//        
//        connections[i] = vector<int>(k);
//        
//        // in counter-clockwise order
//        for (int j = k - 1; j >= 0; j--) {
//            cin >> connections[i][j];
//        }
//    }
//    
//    int Q;  // number of queries
//    cin >> Q;
//    
//    for (int i = 0; i < Q; i++) {
//        int firstRoom;  // starting room to query
//        cin >> firstRoom;
//        
//        int maxCorridors = 0;
//        
//        // for each possible starting path
//        for (int secondRoom : connections[firstRoom]) {
//            int numCorridors = 1;
//            
//            int previousRoom = firstRoom;
//            int currentRoom = secondRoom;
//            
//            while (currentRoom != firstRoom) {
//                auto previousIter = find(connections[currentRoom].begin(), connections[currentRoom].end(), previousRoom);
//                
//                auto nextIter = ++previousIter;
//                if (nextIter == connections[currentRoom].end()) {
//                    nextIter = connections[currentRoom].begin();
//                }
//                
//                int nextRoom = *nextIter;
//                
//                previousRoom = currentRoom;
//                currentRoom = nextRoom;
//                numCorridors++;
//            }
//            
//            if (numCorridors > maxCorridors) {
//                maxCorridors = numCorridors;
//            }
//        }
//        
//        cout << maxCorridors << endl;
//    }
//    
//    return 0;
//}




#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define N_MAX 100001

using namespace std;


struct Path {
    int first;
    int second;
    int end;
};

struct classcomp {
    bool operator() (const Path& lhs, const Path& rhs) const {
        return !(lhs.first == rhs.first && lhs.second == rhs.second && lhs.end == rhs.end);
    }
};


vector<int> connections[N_MAX];


int main() {
    int N;      // number of rooms
    cin >> N;
    
    // for each room (i)
    for (int i = 1; i <= N; i++) {
        int k;  // number of corridors connecting to room i
        cin >> k;
        
        connections[i] = vector<int>(k);
        
        // in counter-clockwise order
        for (int j = k - 1; j >= 0; j--) {
            cin >> connections[i][j];
        }
    }
    
    
    
    int Q;  // number of queries
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        map<Path, int, classcomp> memo;
        
        int firstRoom;  // starting room to query
        cin >> firstRoom;
        
        int maxCorridors = 0;
        
        // for each possible starting path
        for (int secondRoom : connections[firstRoom]) {
            int numCorridors = 1;
            
            int previousRoom = firstRoom;
            int currentRoom = secondRoom;
            
            while (currentRoom != firstRoom) {
                auto previousIter = find(connections[currentRoom].begin(), connections[currentRoom].end(), previousRoom);
                
                auto nextIter = ++previousIter;
                if (nextIter == connections[currentRoom].end()) {
                    nextIter = connections[currentRoom].begin();
                }
                
                int nextRoom = *nextIter;
                
                
                
                
                if (memo.find(Path {currentRoom, nextRoom, firstRoom}) != memo.end()) {
                    currentRoom = firstRoom;
                    numCorridors += memo[Path {currentRoom, nextRoom, firstRoom}];
                } else {
                    previousRoom = currentRoom;
                    currentRoom = nextRoom;
                    numCorridors++;
                }
                
                
                memo[Path {firstRoom, secondRoom, currentRoom}] = numCorridors;
            }
            
            if (numCorridors > maxCorridors) {
                maxCorridors = numCorridors;
            }
        }
        
        cout << maxCorridors << endl;
    }
    
    return 0;
}

