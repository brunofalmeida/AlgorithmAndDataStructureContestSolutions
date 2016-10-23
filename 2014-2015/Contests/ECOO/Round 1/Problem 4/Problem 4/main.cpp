#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int cnt = 0;
unordered_map<string, long long> memo;
vector<string> good = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};

long long recurse(string word) {
    if (word.length() == 0) {
	return 1;
    }
    
    long long tot = 0;
    for (int i = 1; i < min(9, (int) word.length() + 1); i++) {
	string cool = word.substr(0, i);
	if (find(good.begin(), good.end(), cool) != good.end()) {
	    string newWord = word.substr(i, word.length() - i);
	    if (memo.count(newWord)) {
		tot += memo[newWord];
	    } else {
		memo[newWord] = recurse(newWord);
		tot += memo[newWord];
	    }
	    // cout <<  memo[newWord] << endl;
	}
    }
    return tot;
}

int main() {
    freopen("DATA42.txt", "r", stdin);
    memo.clear();
    for (int i = 0; i < 10; i++) {
	string word;
	cin >> word;
	cnt = 0;
	cout << recurse(word) << endl;
    }
    
    return 0;
}
