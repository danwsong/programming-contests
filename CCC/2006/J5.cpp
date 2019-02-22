#include <bits/stdc++.h>

using namespace std;

int main() {
    string type;
    cin >> type;

    vector< vector<int> > board(9, vector<int>(9, 0));
    if (type == "a") {
        board[4][5] = board[5][4] = 2;
        board[4][4] = board[5][5] = 1;
    }
    if (type == "b") {
        for (int r = 1; r <= 8; r++) {
            board[r][r] = 2;
            board[r][9 - r] = 1;
        }
    }
    if (type == "c") {
        for (int r = 1; r <= 8; r++) {
            board[r][3] = 2;
            board[r][4] = 2;
            board[r][5] = 1;
            board[r][6] = 1;
        }
    }

    int N;
    cin >> N;

    int player = 2;
    while (N--) {
        int r, c;
        cin >> r >> c;
        board[r][c] = player;
        player = 3 - player;
        
        int nextR = 0, nextC = 0;
        bool found;

        // down
        found = false;
        for (int i = r + 1, j = c; i <= 8; i++) {
            if (board[i][j] == 0)
                break;
            if (board[r][c] == board[i][j]) {
                found = true;
                nextR = i;
                nextC = j;
                break;
            }
        }
        if (found) {
            for (int i = r + 1, j = c; i < nextR; i++) {
                board[i][j] = board[r][c];
            }
        }

        // up
        found = false;
        for (int i = r - 1, j = c; i >= 1; i--) {
            if (board[i][j] == 0)
                break;
            if (board[r][c] == board[i][j]) {
                found = true;
                nextR = i;
                nextC = j;
                break;
            }
        }
        if (found) {
            for (int i = r - 1, j = c; i > nextR; i--) {
                board[i][j] = board[r][c];
            }
        }

        // right
        found = false;
        for (int i = r, j = c + 1; j <= 8; j++) {
            if (board[i][j] == 0)
                break;
            if (board[r][c] == board[i][j]) {
                found = true;
                nextR = i;
                nextC = j;
                break;
            }
        }
        if (found) {
            for (int i = r, j = c + 1; j < nextC; j++) {
                board[i][j] = board[r][c];
            }
        }

        // left
        found = false;
        for (int i = r, j = c - 1; j >= 1; j--) {
            if (board[i][j] == 0)
                break;
            if (board[r][c] == board[i][j]) {
                found = true;
                nextR = i;
                nextC = j;
                break;
            }
        }
        if (found) {
            for (int i = r, j = c - 1; j > nextC; j--) {
                board[i][j] = board[r][c];
            }
        }

        // down right
        found = false;
        for (int i = r + 1, j = c + 1; i <= 8 && j <= 8; i++, j++) {
            if (board[i][j] == 0)
                break;
            if (board[r][c] == board[i][j]) {
                found = true;
                nextR = i;
                nextC = j;
                break;
            }
        }
        if (found) {
            for (int i = r + 1, j = c + 1; i < nextR && j < nextC; i++, j++) {
                board[i][j] = board[r][c];
            }
        }

        // down left
        found = false;
        for (int i = r + 1, j = c - 1; i <= 8 && j >= 1; i++, j--) {
            if (board[i][j] == 0)
                break;
            if (board[r][c] == board[i][j]) {
                found = true;
                nextR = i;
                nextC = j;
                break;
            }
        }
        if (found) {
            for (int i = r + 1, j = c - 1; i < nextR && j > nextC; i++, j--) {
                board[i][j] = board[r][c];
            }
        }

        // up right
        found = false;
        for (int i = r - 1, j = c + 1; i >= 1 && j <= 8; i--, j++) {
            if (board[i][j] == 0)
                break;
            if (board[r][c] == board[i][j]) {
                found = true;
                nextR = i;
                nextC = j;
                break;
            }
        }
        if (found) {
            for (int i = r - 1, j = c + 1; i > nextR && j < nextC; i--, j++) {
                board[i][j] = board[r][c];
            }
        }

        // up left
        found = false;
        for (int i = r - 1, j = c - 1; i >= 1 && j >= 1; i--, j--) {
            if (board[i][j] == 0)
                break;
            if (board[r][c] == board[i][j]) {
                found = true;
                nextR = i;
                nextC = j;
                break;
            }
        }
        if (found) {
            for (int i = r - 1, j = c - 1; i > nextR && j > nextC; i--, j--) {
                board[i][j] = board[r][c];
            }
        }
    }

    int black = 0, white = 0;
    for (int r = 1; r <= 8; r++) {
        for (int c = 1; c <= 8; c++) {
            if (board[r][c] == 1)
                white++;
            if (board[r][c] == 2)
                black++;
        }
    }
    cout << black << " " << white << endl;
    
    return 0;
}
