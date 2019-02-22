#include <bits/stdc++.h>

using namespace std;

int main() {
    string a1;
    getline(cin, a1);
    
    string a2;
    getline(cin, a2);
    
    string b2;
    getline(cin, b2);
    
    string b1 = b2;
    
    map<char, char> encryption;
    
    for (int i = 0; i < a1.size(); i++) {
        encryption[a2[i]] = a1[i];
    }
    
    for (int i = 0; i < b1.size(); i++) {
        if (encryption.find(b2[i]) != encryption.end()) {
            b1[i] = encryption[b2[i]];
        } else {
            b1[i] = '.';
        }
    }
    
    cout << b1 << endl;
    
    return 0;
}
