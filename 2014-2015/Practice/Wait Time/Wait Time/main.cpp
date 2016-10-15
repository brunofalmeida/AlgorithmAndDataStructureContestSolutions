#include <iostream>
#include <map>

using namespace std;

int main() {
	//freopen("in2.txt", "r", stdin);	// file for test input data
	
	
	int M;					// number of lines
	cin >> M;
	
	
	map<int, int> times;	// [person] = total
	map<int, int> messages;	// [person] = time received
	int time = 0;			// time index
	
	for (int i = 0; i < M; i++) {
		char C;				// operation character
		int X;				// friend or time
		cin >> C >> X;
		
		if (C == 'R') {
			if (times.find(X) == times.end())
				times[X] = 0;
			messages[X] = time;
		}
		else if (C == 'S') {
			times[X] += time - messages[X];
			messages.erase(messages.find(X));
		}
		else if (C == 'W') {
			time += X - 2;
		}
		
		time++;
	}
	
	
	for (auto it : times) {
		if (messages.find(it.first) != messages.end())
			cout << it.first << " -1" << endl;
		else
			cout << it.first << " " << it.second << endl;
	}
	
	
	return 0;
}