#include <iostream>
#include <math.h>
using namespace std;

bool is_prime (int n) {
	for (int i = 3; i <= int (sqrt (n)); i ++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int N;
	int counter = 1;

	cin >> N;

	if (N >= 1) {
		cout << 2 << endl;
	}


	for (int num = 3; counter < N; num += 2) {
		if (is_prime (num)) {
			cout << num << endl;
			counter ++;
		}
	}

	return 0;
}

