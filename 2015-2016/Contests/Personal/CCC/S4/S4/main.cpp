#include <iostream>

using namespace std;

struct Ball {
    int size;
    int left;
    int right;
};

int N;          // number
Ball dp[400];    // max size at that position


int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int size;
        cin >> size;
        dp[i] = Ball {size, 0, 0};
    }
    
    
    bool pass = true;
    
    while (pass) {
        pass = false;
        
        for (int i = 0; i < N; i++) {
            cout << dp[i].size << " ";
        }
        cout << endl;
        
        // two adjacent
        for (int i = 0; i < N - 1; i++) {
            
            // three adjacent
            if (i < N - 2 && dp[i].size == dp[i + 2].size && dp[i].right == 0 && dp[i + 2].left == 0) {
                int sum = dp[i].size + dp[i + 1].size + dp[i + 2].size;
                int begin = i - dp[i].left;
                int end = (i + 2) + dp[i + 2].right;
                
                dp[i] = Ball {sum, i - begin, end - i};
                dp[i + 1] = Ball {sum, (i + 1) - begin, end - (i + 1)};
                dp[i + 2] = Ball {sum, (i + 2) - begin, end - (i + 2)};
                pass = true;
            }
            
            else if (dp[i].size == dp[i + 1].size && dp[i].right == 0 && dp[i + 1].left == 0) {
                int sum = dp[i].size + dp[i + 1].size;
                int begin = i - dp[i].left;
                int end = (i + 1) + dp[i + 1].right;
                
                dp[i] = Ball {sum, i - begin, end - i};
                dp[i + 1] = Ball {sum, (i + 1) - begin, end - (i + 1)};
                pass = true;
            }
        }
    }
    
    
    int maximum = 0;
    
    for (int i = 0; i < N; i++) {
        if (dp[i].size > maximum) {
            maximum = dp[i].size;
        }
    }
    
    cout << maximum << endl;
    
    
    return 0;
}
