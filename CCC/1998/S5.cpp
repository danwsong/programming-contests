#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T) {
        int N;
        cin >> N;
        
        int elevation[N + 1][N + 1];
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                cin >> elevation[i][j];
        
        int oxygenThreshold = elevation[1][1];
        
        queue< pair< pair< pair<int, int>, pair<int, int> >, int > > bfs;
        int dist[N + 1][N + 1];
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = 0x7FFFFFFF;
        bfs.push(make_pair(make_pair(make_pair(1, 1), make_pair(1, 1)), 0));
        int solution = -1;
        while (!bfs.empty()) {
            pair<int, int> curPos = bfs.front().first.first;
            pair<int, int> prevPos = bfs.front().first.second;
            int curDist = bfs.front().second;
            bfs.pop();
            
            if (curPos.first <= 0 || curPos.first > N || curPos.second <= 0 || curPos.second > N)
                continue;
            
            if (elevation[curPos.first][curPos.second] > oxygenThreshold || elevation[prevPos.first][prevPos.second] > oxygenThreshold)
                curDist++;

            if (dist[curPos.first][curPos.second] <= curDist)
                continue;
            dist[curPos.first][curPos.second] = curDist;

            if (curPos.first == N && curPos.second == N) {
                solution = curDist;
                break;
            }
            
            if (abs(elevation[curPos.first + 1][curPos.second] - elevation[curPos.first][curPos.second]) <= 2)
                bfs.push(make_pair(make_pair(make_pair(curPos.first + 1, curPos.second), curPos), curDist));
            if (abs(elevation[curPos.first - 1][curPos.second] - elevation[curPos.first][curPos.second]) <= 2)
                bfs.push(make_pair(make_pair(make_pair(curPos.first - 1, curPos.second), curPos), curDist));
            if (abs(elevation[curPos.first][curPos.second + 1] - elevation[curPos.first][curPos.second]) <= 2)
                bfs.push(make_pair(make_pair(make_pair(curPos.first, curPos.second + 1), curPos), curDist));
            if (abs(elevation[curPos.first][curPos.second - 1] - elevation[curPos.first][curPos.second]) <= 2)
                bfs.push(make_pair(make_pair(make_pair(curPos.first, curPos.second - 1), curPos), curDist));
        }
        
        if (solution == -1)
            cout << "CANNOT MAKE THE TRIP\n";
        else
            cout << solution << "\n";
        
        T--;
        cout << "\n";
    }
    
    return 0;
}
