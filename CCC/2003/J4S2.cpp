#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string blank;
    getline(cin, blank);
    
    for (int n = 0; n < N; n++) {
        vector<string> syllables(4, "");
        for (int i = 0; i < 4; i++) {
            // read next line
            string line;
            getline(cin, line);
            
            // to lowercase
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            
            // get last word
            string word = "";
            for (int j = 0; j < line.size(); j++) {
                if (line[j] == ' ') {
                    word = "";
                } else {
                    word += line[j];
                }
            }
            
            // get last syllable
            int idx;
            for (idx = word.size() - 1; idx >= 0; idx--)
                if (word[idx] == 'a' || word[idx] == 'e' || word[idx] == 'i' || word[idx] == 'o' || word[idx] == 'u')
                    break;
            
            if (idx == -1)
                idx++;
            
            for (; idx < word.size(); idx++)
                syllables[i] += word[idx];
        }
        
        if (syllables[0] == syllables[1] && syllables[1] == syllables[2] && syllables[2] == syllables[3]) {
            cout << "perfect" << endl;
        } else if (syllables[0] == syllables[1] && syllables[2] == syllables[3]) {
            cout << "even" << endl;
        } else if (syllables[0] == syllables[2] && syllables[1] == syllables[3]) {
            cout << "cross" << endl;
        } else if (syllables[0] == syllables[3] && syllables[1] == syllables[2]) {
            cout << "shell" << endl;
        } else {
            cout << "free" << endl;
        }
    }
    
    return 0;
}
