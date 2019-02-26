#include <bits/stdc++.h>

using namespace std;

int main() {
    int M;
    cin >> M;
    
    int final[101] = { 0 }, reply[101] = { 0 }, sent[101] = { 0 };
    
    int time = 0;
    for(int i = 0; i < M; i++) {
        string op;
        int X;
        cin >> op >> X;
        
        if (op == "S") {
            final[X] += time - sent[X];
            reply[X] = 1;
            time++;
        } else if (op == "R") {
            sent[X] = time;
            reply[X] = -1;
            time++;
        } else {
            time += X - 1;
        }
    }
    
    for(int i = 1; i <= 100; i++) {
        if (reply[i]) {
            if (reply[i] > 0)
                cout << i << " " << final[i] << endl;
            else
                cout << i << " " << reply[i] << endl;
        }
    }
    
    return 0;
}
