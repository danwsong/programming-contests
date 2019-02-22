#include <bits/stdc++.h>

using namespace std;

bool isMonkeyWord(string word);
bool isAWord(string word);

bool isMonkeyWord(string word) {
    if (isAWord(word))
        return true;
    int nextN = word.find("N");
    while (nextN != -1 && nextN < word.size() - 1) {
        if (isAWord(word.substr(0, nextN)) && isMonkeyWord(word.substr(nextN + 1, word.size() - nextN - 1)))
            return true;
        nextN = word.find("N", nextN + 1);
    }
    return false;
}

bool isAWord(string word) {
    if (word == "A" || (word[0] == 'B' && word[word.size() - 1] == 'S' && isMonkeyWord(word.substr(1, word.size() - 2))))
        return true;
    return false;
}

int main() {
    string word;
    do {
        cin >> word;
        if (word == "X")
            break;
        cout << (isMonkeyWord(word) ? "YES" : "NO") << "\n";
    } while (true);
    
    return 0;
}
