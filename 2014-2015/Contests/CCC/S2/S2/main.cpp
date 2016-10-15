#include <iostream>
#include <vector>

using namespace std;


int J;	// number of jerseys
int A;	// number of athletes

vector< pair<int, bool> > jerseys;	// size, flag

vector< pair<int, int> > athletes;	// size, jersey number


void input() {
	cin >> J;
	cin >> A;
	
	jerseys.resize(J + 1);
	for (int i = 1; i <= J; i++) {
		char size;
		cin >> size;
		
		if (size == 'S')
			jerseys[i] = pair<int, bool> (0, false);
		else if (size == 'M')
			jerseys[i] = pair<int, bool> (1, false);
		else if (size == 'L')
			jerseys[i] = pair<int, bool> (2, false);
	}
	
	athletes.resize(A + 1);
	for (int i = 1; i <= A; i++) {
		char size;
		cin >> size;
		
		int number;
		cin >> number;
		
		if (size == 'S')
			athletes[i] = pair<int, int> (0, number);
		else if (size == 'M')
			athletes[i] = pair<int, int> (1, number);
		else if (size == 'L')
			athletes[i] = pair<int, int> (2, number);
	}
}


int main() {
	input();
	
	int counter = 0;
	
	for (int i = 1; i <= A; i++) {
		int size = athletes[i].first;
		int number = athletes[i].second;
		
		if (jerseys[number].first >= size && !jerseys[number].second) {
			counter++;
			jerseys[number].second = true;
		}
	}
	
	cout << counter << endl;
	
    return 0;
}
