#include <bits/stdc++.h>

using namespace std;

int main() {
    int distance;
    cin >> distance;
    
    int club;
    cin >> club;
    
    vector<int> clubs(club);
    for (int i = 0; i < club; i++) {
        cin >> clubs[i];
    }
    
    queue<pair<int, int>> bfs;
    vector<int> visited(distance + 1);
    bfs.push(make_pair(0, 0));
    bool flag = false;
    while (!bfs.empty()) {
        pair<int, int> next = bfs.front();
        bfs.pop();  
        
        for (int i = 0; i < club; i++) {
            if (next.first + clubs[i] == distance) {
                cout << "Roberta wins in " << next.second + 1 << " strokes.";
                flag = true;
                goto end;
            }
            if (next.first + clubs[i] < distance && !visited[next.first + clubs[i]]) {
                visited[next.first + clubs[i]] = true;
                bfs.push(make_pair(next.first + clubs[i], next.second + 1));
            }
        }
    }
end:
    
    if (!flag)
        cout << "Roberta acknowledges defeat." << endl;
    
    return 0;
}
