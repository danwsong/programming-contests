#include <bits/stdc++.h>

using namespace std;

bool isNum(string s) {
    return s.find_first_not_of("0123456789") == string::npos;
}

int main() {
    int T;
    scanf("%d\n", &T);
    while (T) {
        string s;
        getline(cin, s);
        
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && isalnum(s[i - 1])) {
                
            } else if (i + 8 < s.size() && isalnum(s[i + 8])) {
                
            } else if (i + 7 >= s.size()) {
                
            } else if (isNum(s.substr(i, 2)) && stoi(s.substr(i, 2)) >= 1 && stoi(s.substr(i, 2)) <= 31 && s[i + 2] == '/' && isNum(s.substr(i + 3, 2)) && stoi(s.substr(i + 3, 2)) >= 1 && stoi(s.substr(i + 3, 2)) <= 12 && s[i + 5] == '/' && isNum(s.substr(i + 6, 2))) {
                if (stoi(s.substr(i + 6, 2)) < 25) {
                    s = s.substr(0, i + 6) + "20" + s.substr(i + 6);
                } else {
                    s = s.substr(0, i + 6) + "19" + s.substr(i + 6);
                }
                i += 2;
                continue;
            }
            if (i > 0 && isalnum(s[i - 1])) {
                
            } else if (i + 8 < s.size() && isalnum(s[i + 8])) {
                
            } else if (i + 7 >= s.size()) {
                
            } else if (isNum(s.substr(i, 2)) && s[i + 2] == '.' && isNum(s.substr(i + 3, 2)) && stoi(s.substr(i + 3, 2)) >= 1 && stoi(s.substr(i + 3, 2)) <= 12 && s[i + 5] == '.' && isNum(s.substr(i + 6, 2)) && stoi(s.substr(i + 6, 2)) >= 1 && stoi(s.substr(i + 6, 2)) <= 31) {
                if (stoi(s.substr(i, 2)) < 25) {
                    s = s.substr(0, i) + "20" + s.substr(i);
                } else {
                    s = s.substr(0, i) + "19" + s.substr(i);
                }
                i += 2;
                continue;
            }
            if (i > 0 && isalnum(s[i - 1])) {
                
            } else {
                int x = -1;
                if (i + 6 < s.size() && s.substr(i, 7) == "January")
                    x = i + 7;
                if (i + 7 < s.size() && s.substr(i, 8) == "February")
                    x = i + 8;
                if (i + 4 < s.size() && s.substr(i, 5) == "March")
                    x = i + 5;
                if (i + 4 < s.size() && s.substr(i, 5) == "April")
                    x = i + 5;
                if (i + 2 < s.size() && s.substr(i, 3) == "May")
                    x = i + 3;
                if (i + 3 < s.size() && s.substr(i, 4) == "June")
                    x = i + 4;
                if (i + 3 < s.size() && s.substr(i, 4) == "July")
                    x = i + 4;
                if (i + 5 < s.size() && s.substr(i, 6) == "August")
                    x = i + 6;
                if (i + 8 < s.size() && s.substr(i, 9) == "September")
                    x = i + 9;
                if (i + 6 < s.size() && s.substr(i, 7) == "October")
                    x = i + 7;
                if (i + 7 < s.size() && s.substr(i, 8) == "November")
                    x = i + 8;
                if (i + 7 < s.size() && s.substr(i, 8) == "December")
                    x = i + 8;
                if (x == -1) {
                    
                } else if (x + 7 < s.size() && isalnum(s[x + 7])) {
                    
                } else if (x + 6 >= s.size()) {
                    
                } else if (s[x] == ' ' && isNum(s.substr(x + 1, 2)) && stoi(s.substr(x + 1, 2)) >= 1 && stoi(s.substr(x + 1, 2)) <= 31 && s[x + 3] == ',' && s[x + 4] == ' ' && isNum(s.substr(x + 5, 2))) {
                    if (stoi(s.substr(x + 5, 2)) < 25) {
                        s = s.substr(0, x + 5) + "20" + s.substr(x + 5);
                    } else {
                        s = s.substr(0, x + 5) + "19" + s.substr(x + 5);
                    }
                    i += 2;
                    continue;
                }
            }
        }
        
        cout << s << "\n";
        
        T--;
    }
    
    return 0;
}
