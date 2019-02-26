#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
    string s;
    cin >> s;
    
    int maxLen = 1;
    for (int i = 0; i < s.size(); i++)
        for (int j = s.size(); j > i + 1; j--)
            if (isPalindrome(s.substr(i, j - i)))
                maxLen = max(maxLen, j - i);

    cout << maxLen << endl;
    
    return 0;
}
