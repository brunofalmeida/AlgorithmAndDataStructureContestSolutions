#include <iostream>
#include <vector>
#include <utility>

using namespace std;


const int MAX = 999999;

int VA, VB;
int M;


pair<int, int> fill(pair<int, int> cups, char cup) {
    if (cup == 'A')
        cups.first = VA;
    else
        cups.second = VB;
    return cups;
}

pair<int, int> pour(pair<int, int> cups, char cup) {
    if (cup == 'A') {
        int give = cups.first;
        int receive = VB - cups.second;
        cups.first -= min(give, receive);
        cups.second += min(give, receive);
    }
    else {
        int give = cups.second;
        int receive = VA - cups.first;
        cups.second -= min(give, receive);
        cups.first += min(give, receive);
    }
    return cups;
}

pair<int, int> chug(pair<int, int> cups, char cup) {
    if (cup == 'A')
        cups.first = 0;
    else
        cups.second = 0;
    return cups;
}

void updateSteps(int& minSteps, vector<string>& minStepsList, vector<string> steps, string step) {
    if (steps.size() == 1 and steps[0] == "yes") {
        minSteps = 1;
        minStepsList = {step};
    }
    else if (0 < steps.size() < minSteps) {
        minSteps = (int)steps.size() + 1;
        minStepsList = {step};
        minStepsList.insert(minStepsList.end(), steps.begin(), steps.end());
    }
}


vector<string> recurse(pair<int, int> cupsOld) {
    if (cupsOld.first == M or cupsOld.second == M) {
        return vector<string> {"yes"};
    }
    else {
        int minSteps = MAX;
        vector<string> minStepsList;
        
        updateSteps(minSteps, minStepsList, recurse(fill(cupsOld, 'A')), "fill A");
        updateSteps(minSteps, minStepsList, recurse(fill(cupsOld, 'B')), "fill B");
        updateSteps(minSteps, minStepsList, recurse(pour(cupsOld, 'A')), "pour A B");
        updateSteps(minSteps, minStepsList, recurse(pour(cupsOld, 'B')), "pour B A");
        updateSteps(minSteps, minStepsList, recurse(chug(cupsOld, 'A')), "chug A");
        updateSteps(minSteps, minStepsList, recurse(chug(cupsOld, 'B')), "chug B");
        
        return minStepsList;
    }
}


int main(int argc, const char * argv[]) {
    cin >> VA >> VB >> M;
    
    vector<string> steps = recurse(make_pair(0, 0));
    
    if (steps.size() == 0) {
        cout << "Not possible" << endl;
    }
    else {
        for (string step : steps)
            cout << step << endl;
    }
    
    return 0;
}
