#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> data(N);
    for (int i = 0; i < N; i++)
        cin >> data[i];
    
    sort(data.begin(), data.end());
    
    vector<int> data1(N - N / 2), data2(N / 2);
    for (int i = 0; i < N - N / 2; i++)
        data1[N - N / 2 - 1 - i] = data[i];
    for (int i = 0; i < N / 2; i++)
        data2[i] = data[N - N / 2 + i];
    
    for (int i = 0; i < N - N / 2; i++) {
        cout << data1[i];
        if (i < N / 2) {
            cout << " " << data2[i];
        }
        if (i == N - N / 2 - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    
    return 0;
}

