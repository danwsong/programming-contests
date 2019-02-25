#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, bits;
    cin >> N >> bits;

    vector<int> lights;
    for (int i = 0; i < N; i++) {
        int row = 0;
        for (int j = 0; j < bits; j++) {
            row <<= 1;
            int bit;
            cin >> bit;
            row |= bit;
        }
        lights.push_back(row);
    }

    vector<bool> top((int) pow(2, bits), false), bottom;
    top[lights[0]] = true;
    for (int i = 1; i < N; i++) {
        bottom = vector<bool>((int) pow(2, bits), false);
        bottom[lights[i]] = true;
        for (int j = 0; j < top.size(); j++) {
            if (top[j]) {
                bottom[j ^ lights[i]] = true;
            }
        }
        top = bottom;
    }

    int combinations = 0;
    for (int i = 0; i < top.size(); i++) {
        if (top[i]) {
            combinations++;
        }
    }
    cout << combinations << endl;
    
    return 0;
}
