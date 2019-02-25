#include <bits/stdc++.h>

using namespace std;

int main() {
    long N, T;
    cin >> N >> T;
    
    vector< vector<long> > rectangles;
    vector<long> iToX, iToY;
    for (long i = 0; i < N; i++) {
        vector<long> rectangle(5);
        for (long j = 0; j < 5; j++)
            cin >> rectangle[j];
        iToX.push_back(rectangle[0]);
        iToY.push_back(rectangle[1]);
        iToX.push_back(rectangle[2]);
        iToY.push_back(rectangle[3]);
        rectangles.push_back(rectangle);
    }
    sort(iToX.begin(), iToX.end());
    iToX.erase(unique(iToX.begin(), iToX.end()), iToX.end());
    sort(iToY.begin(), iToY.end());
    iToY.erase(unique(iToY.begin(), iToY.end()), iToY.end());
    
    map<long, long> xToI, yToI;
    for (long i = 0; i < iToX.size(); i++)
        xToI[iToX[i]] = i;
    for (long i = 0; i < iToY.size(); i++)
        yToI[iToY[i]] = i;
    
    vector< vector<long> > differenceArray(iToY.size(), vector<long>(iToX.size(), 0));
    for (long i = 0; i < N; i++) {
        for (long j = yToI[rectangles[i][1]]; j < yToI[rectangles[i][3]]; j++) {
            differenceArray[j][xToI[rectangles[i][0]]] += rectangles[i][4];
            differenceArray[j][xToI[rectangles[i][2]]] -= rectangles[i][4];
        }
    }
    
    long area = 0;
    for (long i = 0; i < iToY.size() - 1; i++) {
        for (long j = 0; j < iToX.size() - 1; j++) {
            differenceArray[i][j + 1] += differenceArray[i][j];
            if (differenceArray[i][j] >= T)
                area += (iToY[i + 1] - iToY[i]) * (iToX[j + 1] - iToX[j]);
        }
    }
    cout << area << endl;
    
    return 0;
}
