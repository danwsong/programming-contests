#include <bits/stdc++.h>

using namespace std;

string S[10][9];
int vals[10][9];

bool isNum(string s) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}

bool evaluate(string s, int x, int y) {
    vector<string> tokens;
    size_t pos;
    while ((pos = s.find("+")) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    tokens.push_back(s);
    
    int result = 0;
    for (int i = 0; i < tokens.size(); i++) {
        int row = tokens[i][0] - 'A', col = tokens[i][1] - '1';
        if (vals[row][col] == -1)
            return false;
        result += vals[row][col];
    }
    vals[x][y] = result;
    
    return true;
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> S[i][j];
            vals[i][j] = -1;
            if (isNum(S[i][j]))
                vals[i][j] = stoi(S[i][j]);
        }
    }

    bool changed = true;
    while (changed) {
        changed = false;
        
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 9; j++)
                if (vals[i][j] == -1)
                    changed = changed || evaluate(S[i][j], i, j);
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (vals[i][j] == -1)
                cout << "*";
            else
                cout << vals[i][j];
            if (j < 8)
                cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
