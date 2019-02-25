#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    int C;
    cin >> C;
    
    vector<int> chores(C);
    for (int i = 0; i < C; i++)
        cin >> chores[i];
        
    sort(chores.begin(), chores.end());
    
    int sum = 0, pointer = 0;
    while (sum < T && pointer < C) {
        if (sum + chores[pointer] <= T)
            sum += chores[pointer++];
        else
            break;
    }
            
    cout << pointer << endl;
    
    return 0;
}
