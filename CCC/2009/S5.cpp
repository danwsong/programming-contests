#include <bits/stdc++.h>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    int city[rows + 1][cols + 1];
    for (int r = 0; r <= rows; r++)
        for (int c = 0; c <= cols; c++)
            city[r][c] = 0;
    
    int shops;
    cin >> shops;
    while (shops--) {
        int row, col, radius, bitrate;
        cin >> col >> row >> radius >> bitrate;
        
        row--;
        col--;
        
        for (int c = max(0, col - radius); c <= min(cols - 1, col + radius); c++) {
            int leftBound = max(0, row - (int) sqrt(pow(radius, 2) - pow(col - c, 2)));
            int rightBound = min(rows - 1, row + (int) sqrt(pow(radius, 2) - pow(col - c, 2)));
            city[leftBound][c] += bitrate;
            city[rightBound + 1][c] -= bitrate;
        }
    }
    
    int maxBitrate = 0, maxCount = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (r > 0)
                city[r][c] += city[r - 1][c];
            if (city[r][c] == maxBitrate)
                maxCount++;
            if (city[r][c] > maxBitrate) {
                maxBitrate = city[r][c];
                maxCount = 1;
            }
        }
    }
    cout << maxBitrate << endl << maxCount << endl;
    
    return 0;
}
