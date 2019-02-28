#include <bits/stdc++.h>

using namespace std;

int N;

vector<vector<int>> rotate(vector<vector<int>> matrix) {
    vector<vector<int>> rotated(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[i][j] = matrix[N - j - 1][i];
        }
    }
    return rotated;
}

bool valid(vector<vector<int>> matrix) {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] < matrix[i][j - 1])
                return false;
            if (matrix[i][j] < matrix[i - 1][j])
                return false;
        }
    }
    return true;
}

int main() {
    cin >> N;
    
    vector<vector<int>> data(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> data[i][j];
	
    while (!valid(data)) {
        data = rotate(data);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}