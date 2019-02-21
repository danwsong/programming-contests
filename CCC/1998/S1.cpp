#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    string blank;
    getline(cin, blank);
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        
        string censored = "";
        
        int idx = 0;
        string nextWord = "";
        while (idx < line.size()) {
            if (line[idx] == ' ') {
                if (nextWord.size() == 4)
                    nextWord = "****";
                censored += nextWord + " ";
                nextWord = "";
            } else {
                nextWord += line[idx];
            }
            idx++;
        }
        if (nextWord.size() == 4)
            nextWord = "****";
        censored += nextWord;
        cout << censored << endl;
    }
    
    return 0;
}
