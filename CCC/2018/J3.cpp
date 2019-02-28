#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> dist(4);
    for (int i = 0; i < 4; i++)
        cin >> dist[i];
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int sum = 0;
            for (int k = i; k < j; k++)
                sum += dist[k];
            for (int k = j; k < i; k++)
                sum += dist[k];
            cout << sum << " ";
        }
        cout << endl;
    }
    
    return 0;
}