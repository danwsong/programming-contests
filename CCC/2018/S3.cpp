#include <bits/stdc++.h>

using namespace std;

struct position {
    int x, y;
    
    position() {
        x = 0;
        y = 0;
    }
    
    position(int xParam, int yParam) {
        x = xParam;
        y = yParam;
    }
};

struct node {
    position pos;
    int dist;
    
    node(position posParam, int distParam) {
        pos = posParam;
        dist = distParam;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> map(N);
    position robot;
    vector<position> cameras;
    for (int i = 0; i < N; i++) {
        cin >> map[i];
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'S')
                robot = position(i, j);
            if (map[i][j] == 'C')
                cameras.push_back(position(i, j));
        }
    }
    
    vector<vector<bool>> safe(N, vector<bool>(M, true));
    for (int c = 0; c < cameras.size(); c++) {
        for (int i = cameras[c].x; i < N; i++) {
            if (map[i][cameras[c].y] == 'W')
                break;
            safe[i][cameras[c].y] = false;
        }
        for (int i = cameras[c].x; i >= 0; i--) {
            if (map[i][cameras[c].y] == 'W')
                break;
            safe[i][cameras[c].y] = false;
        }
        for (int j = cameras[c].y; j < M; j++) {
            if (map[cameras[c].x][j] == 'W')
                break;
            safe[cameras[c].x][j] = false;
        }
        for (int j = cameras[c].y; j >= 0; j--) {
            if (map[cameras[c].x][j] == 'W')
                break;
            safe[cameras[c].x][j] = false;
        }
    }
    
    queue<node> bfs;
    bfs.push(node(robot, 0));
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> solution(N, vector<int>(M, -1));
    
    while (!bfs.empty()) {
        node next = bfs.front();
        bfs.pop();
        
        if (next.pos.x < 0 || next.pos.x >= N || next.pos.y < 0 || next.pos.y >= M)
            continue;
        
        while (map[next.pos.x][next.pos.y] == 'L' || map[next.pos.x][next.pos.y] == 'R' || map[next.pos.x][next.pos.y] == 'U' || map[next.pos.x][next.pos.y] == 'D') {
            if (visited[next.pos.x][next.pos.y])
                goto end;
            if (map[next.pos.x][next.pos.y] == 'L') {
                visited[next.pos.x][next.pos.y] = true;
                next.pos.y--;
            }
            if (map[next.pos.x][next.pos.y] == 'R') {
                visited[next.pos.x][next.pos.y] = true;
                next.pos.y++;
            }
            if (map[next.pos.x][next.pos.y] == 'U') {
                visited[next.pos.x][next.pos.y] = true;
                next.pos.x--;
            }
            if (map[next.pos.x][next.pos.y] == 'D') {
                visited[next.pos.x][next.pos.y] = true;
                next.pos.x++;
            }
        }
        
        if (visited[next.pos.x][next.pos.y])
            continue;
        visited[next.pos.x][next.pos.y] = true;
        if (next.pos.x < 0 || next.pos.x >= N || next.pos.y < 0 || next.pos.y >= M)
            continue;
        if (map[next.pos.x][next.pos.y] == 'W')
            continue;
        if (!safe[next.pos.x][next.pos.y])
            continue;
        if (map[next.pos.x][next.pos.y] == '.')
            solution[next.pos.x][next.pos.y] = next.dist;
        
        bfs.push(node(position(next.pos.x + 1, next.pos.y), next.dist + 1));
        bfs.push(node(position(next.pos.x - 1, next.pos.y), next.dist + 1));
        bfs.push(node(position(next.pos.x, next.pos.y + 1), next.dist + 1));
        bfs.push(node(position(next.pos.x, next.pos.y - 1), next.dist + 1));
        
    end:
        continue;
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == '.')
                cout << solution[i][j] << endl;
    
    return 0;
}