#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	freopen("bgm.in", "r", stdin);
	freopen("bgm.out", "w", stdout);
	
	
	int N;
	scanf("%d\n", &N);
	
	map< char, vector<int> > values;
	
	for (int i = 0; i < N; i++) {
		char variable;
		int value;
		scanf("%c %d\n", &variable, &value);
		
		values[variable].push_back(value);
	}
	
	
	long long answer = 0;
	
	for (int b : values['B']) {
		for (int e : values['E']) {
			for (int s : values['S']) {
				for (int i : values['I']) {
					for (int g : values['G']) {
						for (int o : values['O']) {
							for (int m : values['M']) {
								long long expression = (b + e + s + s + i + e) * (g + o + e + s) * (m + o + o);
								if (expression % 7 == 0) {
									answer++;
								}
							}
						}
					}
				}
			}
		}
	}
	
	
	printf("%lld\n", answer);
	
	
    return 0;
}
