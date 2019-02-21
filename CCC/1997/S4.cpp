#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    string nextLine;
    getline(cin, nextLine);
    while (T) {
        map<string, int> dict;
        int word = 1;
        getline(cin, nextLine);
        while (nextLine != "") {
            istringstream buffer(nextLine);
            istream_iterator<string> begin(buffer), end;
            vector<string> words(begin, end);
            for (int i = 0; i < words.size(); i++) {
                if (dict.find(words[i]) == dict.end()) {
                    dict[words[i]] = word++;
                    cout << words[i];
                } else {
                    cout << dict[words[i]];
                }
                if (i < words.size() - 1)
                    cout << " ";
            }
            cout << "\n";
            getline(cin, nextLine);
        }
        T--;
        cout << "\n";
    }
    
    return 0;
}
