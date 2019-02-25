#include <bits/stdc++.h>

using namespace std;

int valueOfRomanNumeral(char c) {
    switch (c) {
        case 'I':
            return 1;
            break;
            
        case 'V':
            return 5;
            break;
            
        case 'X':
            return 10;
            break;
            
        case 'L':
            return 50;
            break;
            
        case 'C':
            return 100;
            break;
            
        case 'D':
            return 500;
            break;
            
        case 'M':
            return 1000;
            break;
            
        default:
            break;
    }
    
    return 0;
}

int main() {
    string s;
    cin >> s;
    
    int sum = 0;
    for (int i = 0; i < s.size(); i += 2) {
        int arabic = s[i] - '0', roman = valueOfRomanNumeral(s[i + 1]);
        if (i < s.size() - 2 && roman < valueOfRomanNumeral(s[i + 3]))
            sum -= arabic * roman;
        else
            sum += arabic * roman;
    }
	cout << sum << endl;
    
    return 0;
}
