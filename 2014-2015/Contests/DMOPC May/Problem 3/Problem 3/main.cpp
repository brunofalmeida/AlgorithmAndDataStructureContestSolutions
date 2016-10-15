#include <iostream>
#include <set>

using namespace std;

int main() {
	int N;	// number of mollusks
	cin >> N;
	
	int A;	// number of right halves
	int B;	// number of left halves
	cin >> A >> B;
	
	
	set<int> incomplete;
	int complete = 0;
	
	// right
	for (int i = 0; i < A; i++) {
		int id;
		cin >> id;
		
		incomplete.insert(id);
	}
	
	// left
	for (int i = 0; i < B; i++) {
		int id;
		cin >> id;
		
		if (incomplete.find(id) != incomplete.end()) {
			incomplete.erase(id);
			complete++;
		}
	}
	
	
	cout << (N - complete) << endl;
	
	
    return 0;
}
