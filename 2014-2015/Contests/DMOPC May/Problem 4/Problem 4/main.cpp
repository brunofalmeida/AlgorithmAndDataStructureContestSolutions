#include <iostream>
#include <vector>
//#include <ctime>

using namespace std;



int main() {
	//clock_t clockBegin = clock();
	
	
	int N;	// number to find
	cin >> N;
	
	// first number in each row
	// bound = ~45000 rows
	vector<int> memo(45001);
	memo[1] = 1;
	
	for (int x = 1; x <= 45000; x++) {
		
		// calculate number in next row
		memo[x + 1] = memo[x] + x;

		// find row number
		if (memo[x] <= N and N < memo[x + 1]) {
			
			// find sum
			int seriesBegin = memo[x];
			int seriesEnd = memo[x + 1] - 1;
			
			cout << int((seriesEnd - seriesBegin + 1) / 2.0 * (seriesBegin + seriesEnd)) << endl;
			
			break;
		}
	}
	
	
	//clock_t clockEnd = clock();
	//cout << double(clockEnd - clockBegin) / CLOCKS_PER_SEC << endl;
	
	
    return 0;
}
