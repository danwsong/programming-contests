#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    map<string, string> table;
    for (int i = 0; i < N; i++) {
        string key, val;
        cin >> val >> key;
        table[key] = val;
    }
    
    string encoded, decoded = "";
    cin >> encoded;
    int pos = 0;
    while (pos < encoded.size()) {
        int len = 0;
        while (table.find(encoded.substr(pos, len)) == table.end()) {
            len++;
        }
        decoded += table[encoded.substr(pos, len)];
        pos += len;
    }
    cout << decoded << endl;
    
    return 0;
}
