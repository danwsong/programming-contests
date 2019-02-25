#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    int charCount[26] = { 0 };
    for (int i = 0; i < a.size(); i++)
        if (a[i] != ' ')
            charCount[a[i] - 'A']++;
    for (int i = 0; i < b.size(); i++)
        if (b[i] != ' ')
            charCount[b[i] - 'A']--;
    
    bool isAnagram = true;
    for (int i = 0; i < 26; i++)
        if (charCount[i])
            isAnagram = false;
    
    cout << "Is " << (isAnagram ? "" : "not ") << "an anagram.\n";
    
    return 0;
}
