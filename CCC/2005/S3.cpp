#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector< vector<int> > tensor;
    int rows = 1, cols = 1;
    for (int n = 0; n < N; n++) {
        int r, c;
        cin >> r >> c;
        if (n == 0) {
            tensor = vector< vector<int> >(r, vector<int>(c));
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cin >> tensor[i][j];
                }
            }
        } else {
            vector< vector<int> > product(rows * r, vector<int>(cols * c));
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int val;
                    cin >> val;
                    for (int u = 0; u < rows; u++) {
                        for (int v = 0; v < cols; v++) {
                            product[u * r + i][v * c + j] = tensor[u][v] * val;
                        }
                    }
                }
            }
            tensor = product;
        }
        rows *= r;
        cols *= c;
    }
    
    int maxVal = numeric_limits<int>::min(), minVal = numeric_limits<int>::max(), maxRow = maxVal, minRow = minVal, maxCol = maxVal, minCol = minVal;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maxVal = max(maxVal, tensor[i][j]);
            minVal = min(minVal, tensor[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += tensor[i][j];
        }
        maxRow = max(maxRow, sum);
        minRow = min(minRow, sum);
    }
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += tensor[i][j];
        }
        maxCol = max(maxCol, sum);
        minCol = min(minCol, sum);
    }
    cout << maxVal << endl << minVal << endl << maxRow << endl << minRow << endl << maxCol << endl << minCol << endl;
    
    return 0;
}
