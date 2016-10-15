#include <iostream>

using namespace std;

int main() {
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
	
	string S;
	cin >> S;
	
	string T;
	cin >> T;
	
	
	size_t pos = 0;			// search position
	bool repeat = false;	// go through string again
	
	while (true) {
		pos = S.find(T, pos);
		
		if (pos != string::npos) {
			S.erase(S.begin() + pos, S.begin() + pos + T.length());
			repeat = true;
		}
		else {
			if (repeat) {
				pos = 0;
				repeat = false;
			}
			else {
				break;
			}
		}
	}
	
	
	cout << S << endl;
	
	
    return 0;
}
