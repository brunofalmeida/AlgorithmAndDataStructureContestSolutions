#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


struct Formation {
	int O;	// defense
	int V;	// midfield
	int N;	// offense
};


int N;	// number of formations
vector<Formation> formations;

int M;	// number of players
vector<string> players;


void input() {
	cin >> N;
	formations.resize(N);
	
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		int iDash;
		
		iDash = (int)input.find("-");
		formations[i].O = stoi(input.substr(0, iDash));
		input = input.substr(iDash + 1, input.length() - iDash - 1);
		
		iDash = (int)input.find("-");
		formations[i].V = stoi(input.substr(0, iDash));
		input = input.substr(iDash + 1, input.length() - iDash - 1);
		
		formations[i].N = stoi(input);
	}
	
	cin >> M;
	players.resize(M);
	
	for (int i = 0; i < M; i++)
		cin >> players[i];
}

void updateSinglePositions(vector<bool>& defense, vector<bool>& midfield, vector<bool>& offense,
						   int& numDefense, int& numMidfield, int& numOffense) {
	for (int i = 0; i < defense.size(); i++) {
		if (defense[i] and !midfield[i] and !offense[i]) {
			numDefense++;
			defense[i] = false;
		}
		else if (!defense[i] and midfield[i] and !offense[i]) {
			numMidfield++;
			midfield[i] = false;
		}
		else if (!defense[i] and !midfield[i] and offense[i]) {
			numOffense++;
			offense[i] = false;
		}
	}
}

int main(int argc, const char * argv[]) {
	freopen("niko.dummy.in.2", "r", stdin);
	
	input();
	
	for (int n = 0; n < N; n++) {	// for each formation
		vector<bool> defense(M, false);
		vector<bool> midfield(M, false);
		vector<bool> offense(M, false);
		
		for (int i = 0; i < players.size(); i++) {
			if (players[i].find("O") != string::npos)
				defense[i] = true;
			if (players[i].find("V") != string::npos)
				midfield[i] = true;
			if (players[i].find("N") != string::npos)
				offense[i] = true;
		}
		
		int numDefense = 0;
		int numMidfield = 0;
		int numOffense = 0;
		
		bool repeat = true;
		while (repeat) {
			repeat = false;
			
			updateSinglePositions(defense, midfield, offense, numDefense, numMidfield, numOffense);
			int numDefenseRequired = formations[n].O - numDefense;
			int numMidfieldRequired = formations[n].V - numMidfield;
			int numOffenseRequired = formations[n].N - numOffense;
			
			if (numDefenseRequired > numMidfieldRequired and numDefenseRequired > numOffenseRequired) {
				for (int i = 0; i < defense.size(); i++) {
					if (defense[i]) {
						numDefense++;
						defense[i] = false;
						midfield[i] = false;
						offense[i] = false;
						repeat = true;
						break;
					}
				}
			}
			else if (numMidfieldRequired > numDefenseRequired and numMidfieldRequired > numOffenseRequired) {
				for (int i = 0; i < defense.size(); i++) {
					if (midfield[i]) {
						numMidfield++;
						defense[i] = false;
						midfield[i] = false;
						offense[i] = false;
						repeat = true;
						break;
					}
				}
			}
			else if (numOffenseRequired > numDefenseRequired and numOffenseRequired > numMidfieldRequired) {
				for (int i = 0; i < defense.size(); i++) {
					if (offense[i]) {
						numOffense++;
						defense[i] = false;
						midfield[i] = false;
						offense[i] = false;
						repeat = true;
						break;
					}
				}
			}
		}
		
		if (numDefense >= formations[n].O and numMidfield >= formations[n].V and numOffense >= formations[n].N)
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}
	
	
    return 0;
}
