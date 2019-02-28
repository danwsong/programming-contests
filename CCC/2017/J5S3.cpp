#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> wood(2001, 0);
    for (int i = 0; i < N; i++) {
        int woodSize;
        cin >> woodSize;
        wood[woodSize]++;
    }
    
    vector<int> heights(4001, 0);
    vector<int> woodCopy(wood.size());
    for (int height = 1; height <= 4000; height++) {
        for (int i = 0; i < woodCopy.size(); i++) {
            woodCopy[i] = wood[i];
        }
        for (int left = 1; left <= height - left; left++) {
            if (height - left <= 2000) {
                if (left == height - left) {
                    int boards = woodCopy[left] / 2;
                    heights[height] += boards;
                    woodCopy[left] -= boards * 2;
                } else {
                    int boards = min(woodCopy[left], woodCopy[height - left]);
                    woodCopy[left] -= boards;
                    woodCopy[height - left] -= boards;
                    heights[height] += boards;
                }
            }
        }
    }
    
    int maxBoards = 0;
    for (int i = 1; i <= heights.size(); i++) {
        maxBoards = max(maxBoards, heights[i]);
    }
    
    int answer = 0;
    for (int i = 1; i <= heights.size(); i++) {
        if (heights[i] == maxBoards)
            answer++;
    }
    
    cout << maxBoards << " " << answer << endl;
    
    return 0;
}
