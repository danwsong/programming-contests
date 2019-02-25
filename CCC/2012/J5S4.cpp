#include <bits/stdc++.h>

using namespace std;

struct node {
    vector<string> state;
    int level;
    
    node(vector<string> state, int level) {
        this->state = state;
        this->level = level;
    }
};

bool isWin(vector<string> state) {
    for (int i = 0; i < state.size(); i++)
        if (state[i] != to_string(i + 1))
            return false;
    return true;
}

int convertState(vector<string> state) {
    int converted = 0;
    for (int i = 0; i < state.size(); i++) {
        for (int j = 0; j < state[i].size(); j++) {
            converted += i * pow(state.size(), state[i][j] - '1');
        }
    }
    return converted;
}

vector<string> moveCoin(vector<string> curState, int i, int j) {
    vector<string> nextState = curState;
    nextState[j] = nextState[i].substr(0, 1) + nextState[j];
    nextState[i] = nextState[i].substr(1);
    if (j < i && nextState[j].substr(0, 1) == to_string(curState.size()))
        return curState;
    return nextState;
}

int main() {
    int N;
    cin >> N;
    while (N) {
        vector<string> start(N);
        for (int i = 0; i < N; i++)
            cin >> start[i];
        
        queue<node> tree;
        vector<bool> visited(pow(N, N), false);
        tree.push(node(start, 0));
        bool won = false;
        while (!tree.empty()) {
            node cur = tree.front();
            tree.pop();
            
            if (visited[convertState(cur.state)])
                continue;
            visited[convertState(cur.state)] = true;
            
            if (isWin(cur.state)) {
                cout << cur.level << endl;
                won = true;
                break;
            }
            
            for (int i = 0; i < N; i++) {
                if (i + 1 < N && cur.state[i].size() > 0 && (cur.state[i + 1].size() == 0 || cur.state[i][0] < cur.state[i + 1][0]))
                    tree.push(node(moveCoin(cur.state, i, i + 1), cur.level + 1));
                if (i - 1 >= 0 && cur.state[i].size() > 0 && (cur.state[i - 1].size() == 0 || cur.state[i][0] < cur.state[i - 1][0]))
                    tree.push(node(moveCoin(cur.state, i, i - 1), cur.level + 1));
            }
        }
        if (!won)
            cout << "IMPOSSIBLE" << endl;
        
        cin >> N;
    }
    
    return 0;
}
