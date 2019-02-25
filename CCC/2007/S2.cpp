#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector< vector<int> > boxes(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> boxes[i][j];
        }
        sort(boxes[i].begin(), boxes[i].end());
    }
    sort(boxes.begin(), boxes.end(), [](vector<int> a, vector<int> b) {
        return (a[0] * a[1] * a[2]) < (b[0] * b[1] * b[2]);
    });
    
    int M;
    cin >> M;
    for (int m = 0; m < M; m++) {
        vector<int> size(3);
        for (int i = 0; i < 3; i++)
            cin >> size[i];
        sort(size.begin(), size.end());
        int minBox = 0;
        for (int i = 0; i < N; i++) {
            if (boxes[i][0] >= size[0] && boxes[i][1] >= size[1] && boxes[i][2] >= size[2]) {
                minBox = boxes[i][0] * boxes[i][1] * boxes[i][2];
                break;
            }
        }
        if (!minBox)
            cout << "Item does not fit." << endl;
        if (minBox) {
            cout << minBox << endl;
            
        }
    }
    
    return 0;
}
