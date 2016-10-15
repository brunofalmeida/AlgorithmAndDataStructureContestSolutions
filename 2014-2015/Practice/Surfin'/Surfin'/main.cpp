#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;


const string breakStr = "</HTML>";
const string urlBeginStr = "<A HREF=\"";
const string urlEndStr = "\">";

int n;  // number of pages

map<string, int> urlNums;   // URL to page number
int nextIndex = 0;   // index of next node to be added

vector< vector<int> > graph; // adjacency list


// gets index of link, updates map
int getIndex(string url) {
    int urlIndex;
    
    if (urlNums.find(url) != urlNums.end()) {   // if URL has been indexed
        urlIndex = urlNums[url];
    }
    else {  // if URL has not been indexed
        urlIndex = nextIndex++;
        urlNums[url] = urlIndex;
        graph.resize(graph.size() + 1);
    }
    
    return urlIndex;
}


int main() {
    // freopen("in.txt", "r", stdin);
    
    
    cin >> n;
    
    // for each page
    for (int i = 0; i < n; i++) {
        string page;
        getline(cin, page);
        if (page.length() <= 1)
            getline(cin, page);
        
        int pageIndex = getIndex(page);
        
        // for each line
        while (true) {
            string line;
            getline(cin, line);
            
            // </HTML>
            if (line.find(breakStr) != string::npos)
                break;
            
            // <A HREF="URL">
            while ( (line.find(urlBeginStr) != string::npos) and (line.find(urlEndStr) != string::npos) ) {
                size_t urlBegin = line.find(urlBeginStr) + 9;
                size_t urlEnd = line.find(urlEndStr);
                string link = line.substr(urlBegin, urlEnd - urlBegin);
                int linkIndex = getIndex(link);
                
                graph[pageIndex].push_back(linkIndex);
                
                cout << "Link from " << page << " to " << link << endl;
                
                line.erase(0, urlEnd + 2);
            }
        }
    }
    
    cout << endl;
    
    
    // for each URL search pair
    while (true) {
        string url1;
        getline(cin, url1);
        
        if (url1 == "The End")
            break;
        
        string url2;
        getline(cin, url2);
        
        int urlIndex1 = getIndex(url1);
        int urlIndex2 = getIndex(url2);
        
        // DFS
        vector<bool> flag(graph.size());
        flag[urlIndex1] = true;
        
        stack<int> s;
        s.push(urlIndex1);
        
        bool answer = false;
        
        while (s.size() > 0) {
            int index1 = s.top();
            s.pop();
            
            if (index1 == urlIndex2) {
                answer = true;
                break;
            }
            
            for (int index2 : graph[index1]) {
                if (!flag[index2]) {
                    s.push(index2);
                    flag[index2] = true;
                }
            }
        }
        
        if (answer)
            cout << "Can surf from " << url1 << " to " << url2 << endl;
        else
            cout << "Can't surf from " << url1 << " to " << url2 << endl;
    }
    
    
    return 0;
}
