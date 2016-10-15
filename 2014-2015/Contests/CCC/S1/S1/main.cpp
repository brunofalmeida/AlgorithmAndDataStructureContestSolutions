#include <iostream>
#include <vector>

using namespace std;

int main() {
	int K;
	cin >> K;
	
	vector<int> numbers;
	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		
		if (n == 0)
			numbers.erase(numbers.end() - 1);
		else
			numbers.push_back(n);
	}
	
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++)
		sum += numbers[i];
	
	cout << sum << endl;
	
    return 0;
}
