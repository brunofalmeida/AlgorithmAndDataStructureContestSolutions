#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// updates degrees for nodes connected to given mp
void updateDegree( const vector< vector<int> >& graph, const vector<char>& party, vector<int>& degree, int mp ) {
    for (int i = 0; i < graph[mp].size(); i++) {
        int mp2 = graph[mp][i];
        degree[mp2]--;
    }
}

void guess( const vector< vector<int> >& graph, vector<char>& party, vector<int>& degree ) {
    for (int mp = 1; mp < party.size(); mp++) {   // for each MP
        if (party[mp] == 'C') {
            party[mp] = 'B';
            updateDegree(graph, party, degree, mp);
        }
    }
}


int main() {
    // File
    freopen("sabor.dummy.in.1", "r", stdin);
    
    
    // Input
    int N;  // number of MPs
    cin >> N;
    
    vector< vector<int> > graph(N + 1, vector<int>(0));
    vector<int> degree(N + 1, 0);   // number of people with unknown party
    for (int i = 0; i < 5; i++) {
        int P;  // number of pairs fighting
        cin >> P;
        
        for (int ii = 0; ii < P; ii++) {
            int K, L;   // 2 MPs fighting
            cin >> K; cin >> L;
            if ( find(graph[L].begin(), graph[L].end(), K) == graph[L].end() ) {    // if K not in graph[L]
                graph[K].push_back(L);
                graph[L].push_back(K);
                degree[K]++;
                degree[L]++;
            }
        }
    }
    
    
    // Algorithm
    vector<char> party(N + 1, 'C');
    
    party[1] = 'A';
    updateDegree(graph, party, degree, 1);
    
    do {
        bool mustGuess = true;
        
        for (int mp = 1; mp <= N; mp++) {   // for each MP
            if (party[mp] != 'C' and degree[mp] <= 2) {   // if MP's party is known and fought with 2 or less unknown MPs
                
                for (int i = 0; i < graph[mp].size(); i++) {    // for each other MP the MP fought with
                    int mp2 = graph[mp][i];
                    
                    if (party[mp2] == 'C') {    // make other MP the same party
                        party[mp2] = party[mp];
                        updateDegree(graph, party, degree, mp2);
                    }
                }
                
                mustGuess = false;
            }
        }
        
        if (mustGuess)
            guess(graph, party, degree);
    } while ( find( party.begin() + 1, party.end(), 'C' ) != party.end() );
    
    
    // Output
    for (int i = 1; i <= N; i++)
        cout << party[i];
    cout << endl;
    
    
    return 0;
}
