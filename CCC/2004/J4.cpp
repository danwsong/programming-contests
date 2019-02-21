#include <bits/stdc++.h>

using namespace std;

int main() {
    string key, original, encoded = "";
    getline(cin, key);
    getline(cin, original);
    
    for (int i = 0; i < original.size(); i++)
        if (original[i] >= 'A' && original[i] <= 'Z')
            encoded += original[i];
    
    for (int i = 0; i < encoded.size(); i++)
        encoded[i] = (((encoded[i] - 'A') + (key[i % key.size()] - 'A')) % 26) + 'A';
        
    cout << encoded << "\n";
    
    return 0;
}
