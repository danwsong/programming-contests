#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d\n", &N);
    map<string, vector<string>> links;
    for (int i = 0; i < N; i++) {
        string url;
        getline(cin, url);
        links[url] = vector<string>();
        string line;
        getline(cin, line);
        while (line != "</HTML>") {
            size_t start = line.find("<A HREF=\""), end;
            while (start != string::npos) {
                size_t end = line.find("\">", start);
                string link = line.substr(start + 9, end - start - 9);
                cout << "Link from " << url << " to " << link << "\n";
                links[url].push_back(link);
                start = line.find("<A HREF=\"", end);
            }
            getline(cin, line);
        }
    }
    string src, dest;
    getline(cin, src);
    while (src != "The End") {
        getline(cin, dest);
        
        stack<string> dfs;
        dfs.push(src);
        map<string, bool> visited;
        while (!dfs.empty()) {
            string cur = dfs.top();
            dfs.pop();
            
            if (visited.find(cur) != visited.end())
                continue;
            visited[cur] = true;
            
            for (int i = 0; i < links[cur].size(); i++) {
                dfs.push(links[cur][i]);
            }
        }
        
        cout << "Can" << ((visited.find(dest) == visited.end()) ? "'t" : "") << " surf from " << src << " to " << dest << ".\n";
        
        getline(cin, src);
    }
    
    return 0;
}
