#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> rivers(n);
    
    for (int i = 0; i < n; i++)
        cin >> rivers[i];
    
    int op;
    cin >> op;
    while (op != 77) {
        if (op == 99) {
            int idx;
            double flow;
            cin >> idx >> flow;
            
            idx--;
            
            vector<double> temp;
            for (int i = 0; i < rivers.size(); i++) {
                if (idx == i) {
                    temp.push_back(rivers[i] * flow / 100.0);
                    temp.push_back(rivers[i] * (100.0 - flow) / 100.0);
                } else {
                    temp.push_back(rivers[i]);
                }
            }
            rivers = temp;
        }
        if (op == 88) {
            int idx;
            cin >> idx;
            
            idx--;
            
            vector<double> temp;
            for (int i = 0; i < rivers.size(); i++) {
                if (idx == i) {
                    temp.push_back(rivers[i] + rivers[i + 1]);
                    i++;
                } else {
                    temp.push_back(rivers[i]);
                }
            }
            rivers = temp;
        }
        
        cin >> op;
    }
    
    for (int i = 0; i < rivers.size(); i++) {
        cout << (int) round(rivers[i]) << " ";
    }
    
    return 0;
}
