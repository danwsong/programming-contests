#include <bits/stdc++.h>

using namespace std;

bool solve(string a, string b, string c, map<char, int> &dict, vector<bool> assigned, int carry) {
    if (a == "" && b == "" && c == "")
        return true;
    int x = -1, y = -1, z = -1;
    if (dict.find(a[a.size() - 1]) != dict.end())
        x = dict[a[a.size() - 1]];
    if (dict.find(b[b.size() - 1]) != dict.end())
        y = dict[b[b.size() - 1]];
    if (dict.find(c[c.size() - 1]) != dict.end())
        z = dict[c[c.size() - 1]];
    if (a == "")
        x = 0;
    if (b == "")
        y = 0;
    if (c == "")
        z = 0;
    if (x == -1) {
        if (y == -1) {
            if (z == -1) {
                for (int i = 9; i >= 0; i--) {
                    if (a.size() == 1 && i == 0)
                        continue;
                    if (assigned[i])
                        continue;
                    for (int j = 9; j >= 0; j--) {
                        if (i == 7 && j == 5 && a.size() == 4) {
                            cout << "";
                        }
                        if (b.size() == 1 && j == 0)
                            continue;
                        if (assigned[j])
                            continue;
                        int k = (i + j + carry) % 10;
                        if (c.size() == 1 && k == 0)
                            continue;
                        if (assigned[k])
                            continue;
                        if (i == j && a[a.size() - 1] != b[b.size() - 1])
                            continue;
                        if (i != j && a[a.size() - 1] == b[b.size() - 1])
                            continue;
                        if (j == k && b[b.size() - 1] != c[c.size() - 1])
                            continue;
                        if (j != k && b[b.size() - 1] == c[c.size() - 1])
                            continue;
                        if (i == k && a[a.size() - 1] != c[c.size() - 1])
                            continue;
                        if (i != k && a[a.size() - 1] == c[c.size() - 1])
                            continue;
                        map<char, int> newDict = dict;
                        vector<bool> newAssigned = assigned;
                        newDict[a[a.size() - 1]] = i;
                        newDict[b[b.size() - 1]] = j;
                        newDict[c[c.size() - 1]] = k;
                        newAssigned[i] = true;
                        newAssigned[j] = true;
                        newAssigned[k] = true;
                        if (solve(a.substr(0, max((int) a.size() - 1, 0)), b.substr(0, max((int) b.size() - 1, 0)), c.substr(0, max((int) c.size() - 1, 0)), newDict, newAssigned, (i + j + carry) / 10)) {
                            dict = newDict;
                            return true;
                        }
                    }
                }
            } else {
                for (int i = 9; i >= 0; i--) {
                    if (a.size() == 1 && i == 0)
                        continue;
                    if (assigned[i])
                        continue;
                    for (int j = 9; j >= 0; j--) {
                        if (b.size() == 1 && j == 0)
                            continue;
                        if (assigned[j])
                            continue;
                        int k = (i + j + carry) % 10;
                        if (c.size() == 1 && k == 0)
                            continue;
                        if (k != z)
                            continue;
                        if (i == j && a[a.size() - 1] != b[b.size() - 1])
                            continue;
                        if (i != j && a[a.size() - 1] == b[b.size() - 1])
                            continue;
                        map<char, int> newDict = dict;
                        vector<bool> newAssigned = assigned;
                        newDict[a[a.size() - 1]] = i;
                        newDict[b[b.size() - 1]] = j;
                        newAssigned[i] = true;
                        newAssigned[j] = true;
                        if (solve(a.substr(0, max((int) a.size() - 1, 0)), b.substr(0, max((int) b.size() - 1, 0)), c.substr(0, max((int) c.size() - 1, 0)), newDict, newAssigned, (i + j + carry) / 10)) {
                            dict = newDict;
                            return true;
                        }
                    }
                }
            }
        } else {
            if (z == -1) {
                for (int i = 9; i >= 0; i--) {
                    if (a.size() == 1 && i == 0)
                        continue;
                    if (assigned[i])
                        continue;
                    int j = y;
                    if (b.size() == 1 && j == 0)
                        continue;
                    int k = (i + j + carry) % 10;
                    if (c.size() == 1 && k == 0)
                        continue;
                    if (assigned[k])
                        continue;
                    if (i == k && a[a.size() - 1] != c[c.size() - 1])
                        continue;
                    if (i != k && a[a.size() - 1] == c[c.size() - 1])
                        continue;
                    map<char, int> newDict = dict;
                    vector<bool> newAssigned = assigned;
                    newDict[a[a.size() - 1]] = i;
                    newDict[c[c.size() - 1]] = k;
                    newAssigned[i] = true;
                    newAssigned[k] = true;
                    if (solve(a.substr(0, max((int) a.size() - 1, 0)), b.substr(0, max((int) b.size() - 1, 0)), c.substr(0, max((int) c.size() - 1, 0)), newDict, newAssigned, (i + j + carry) / 10)) {
                        dict = newDict;
                        return true;
                    }
                }
            } else {
                for (int i = 9; i >= 0; i--) {
                    if (assigned[i])
                        continue;
                    if (a.size() == 1 && i == 0)
                        continue;
                    int j = y;
                    if (b.size() == 1 && j == 0)
                        continue;
                    int k = (i + j + carry) % 10;
                    if (c.size() == 1 && k == 0)
                        continue;
                    if (k != z)
                        continue;
                    map<char, int> newDict = dict;
                    vector<bool> newAssigned = assigned;
                    newDict[a[a.size() - 1]] = i;
                    newAssigned[i] = true;
                    if (solve(a.substr(0, max((int) a.size() - 1, 0)), b.substr(0, max((int) b.size() - 1, 0)), c.substr(0, max((int) c.size() - 1, 0)), newDict, newAssigned, (i + j + carry) / 10)) {
                        dict = newDict;
                        return true;
                    }
                }
            }
        }
    } else {
        int i = x;
        if (a.size() == 1 && i == 0)
            return false;
        if (y == -1) {
            if (z == -1) {
                for (int j = 9; j >= 0; j--) {
                    if (b.size() == 1 && j == 0)
                        continue;
                    if (assigned[j])
                        continue;
                    int k = (i + j + carry) % 10;
                    if (c.size() == 1 && k == 0)
                        continue;
                    if (assigned[k])
                        continue;
                    if (j == k && b[b.size() - 1] != c[c.size() - 1])
                        continue;
                    if (j != k && b[b.size() - 1] == c[c.size() - 1])
                        continue;
                    map<char, int> newDict = dict;
                    vector<bool> newAssigned = assigned;
                    newDict[b[b.size() - 1]] = j;
                    newDict[c[c.size() - 1]] = k;
                    newAssigned[j] = true;
                    newAssigned[k] = true;
                    if (solve(a.substr(0, max((int) a.size() - 1, 0)), b.substr(0, max((int) b.size() - 1, 0)), c.substr(0, max((int) c.size() - 1, 0)), newDict, newAssigned, (i + j + carry) / 10)) {
                        dict = newDict;
                        return true;
                    }
                }
            } else {
                for (int j = 9; j >= 0; j--) {
                    if (b.size() == 1 && j == 0)
                        continue;
                    if (assigned[j])
                        continue;
                    int k = (i + j + carry) % 10;
                    if (c.size() == 1 && k == 0)
                        continue;
                    if (k != z)
                        continue;
                    map<char, int> newDict = dict;
                    vector<bool> newAssigned = assigned;
                    newDict[b[b.size() - 1]] = j;
                    newAssigned[j] = true;
                    if (solve(a.substr(0, max((int) a.size() - 1, 0)), b.substr(0, max((int) b.size() - 1, 0)), c.substr(0, max((int) c.size() - 1, 0)), newDict, newAssigned, (i + j + carry) / 10)) {
                        dict = newDict;
                        return true;
                    }
                }
            }
        } else {
            int j = y;
            if (b.size() == 1 && j == 0)
                return false;
            int k = (i + j + carry) % 10;
            if (c.size() == 1 && k == 0)
                return false;
            if (z == -1) {
                if (assigned[k])
                    return false;
                map<char, int> newDict = dict;
                vector<bool> newAssigned = assigned;
                newDict[c[c.size() - 1]] = k;
                newAssigned[k] = true;
                if (solve(a.substr(0, max((int) a.size() - 1, 0)), b.substr(0, max((int) b.size() - 1, 0)), c.substr(0, max((int) c.size() - 1, 0)), newDict, newAssigned, (i + j + carry) / 10)) {
                    dict = newDict;
                    return true;
                }
            } else {
                if (k != z)
                    return false;
                if (solve(a.substr(0, max((int) a.size() - 1, 0)), b.substr(0, max((int) b.size() - 1, 0)), c.substr(0, max((int) c.size() - 1, 0)), dict, assigned, (i + j + carry) / 10))
                    return true;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T) {
        string a, b, c;
        cin >> a >> b >> c;
        
        map<char, int> dict;
        vector<bool> assigned(10, false);
        solve(a, b, c, dict, assigned, 0);
        
        for (int i = 0; i < a.size(); i++) {
            cout << dict[a[i]];
        }
        cout << "\n";
        for (int i = 0; i < b.size(); i++) {
            cout << dict[b[i]];
        }
        cout << "\n";
        for (int i = 0; i < c.size(); i++) {
            cout << dict[c[i]];
        }
        cout << "\n";
        
        T--;
        cout << "\n";
    }
    
    return 0;
}
