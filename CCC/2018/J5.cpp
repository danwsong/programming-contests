#include <bits/stdc++.h>

using namespace std;

struct page {
    int number, dist;
    
    page(int numParam, int distParam) {
        number = numParam;
        dist = distParam;
    }
};

int main(int argc, char * argv[]) {
    int N;
    cin >> N;
    
    vector<vector<int>> book(N, vector<int>());
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int choice;
            cin >> choice;
            book[i].push_back(choice - 1);
        }
    }
    
    queue<page> bfs;
    bfs.push(page(0, 1));
    vector<bool> visited(N);
    int shortestPath = N;
    while (!bfs.empty()) {
        page next = bfs.front();
        bfs.pop();
        
        if (visited[next.number])
            continue;
        visited[next.number] = true;
        
        if (book[next.number].size() == 0) {
            shortestPath = min(shortestPath, next.dist);
            continue;
        }
        
        for (int i = 0; i < book[next.number].size(); i++) {
            bfs.push(page(book[next.number][i], next.dist + 1));
        }
    }
    
    bool allVisited = true;
    for (int i = 0; i < N; i++) {
        allVisited = allVisited && visited[i];
    }
    
    cout << (allVisited ? "Y" : "N") << endl;
    cout << shortestPath << endl;
    
    return 0;
}