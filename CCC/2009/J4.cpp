#include <bits/stdc++.h>

using namespace std;

int main() {
    string words[6] = { "WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY" };
    
    int maxLineLength;
    cin >> maxLineLength;
    
    int idx = 0;
    while (idx < 6) {
        int lineLength = 0, lineWords = 0;
        while (lineLength + lineWords - 1 <= maxLineLength && idx + lineWords < 6) {
            lineLength += words[idx + lineWords].size();
            lineWords++;
        }
        if (lineLength + lineWords - 1 > maxLineLength) {
            lineWords--;
            lineLength -= words[idx + lineWords].size();
        }
        
        int spaces = maxLineLength - lineLength;
        
        if (lineWords == 1) {
            cout << words[idx];
            for (int i = 0; i < spaces; i++)
                cout << ".";
            cout << endl;
        } else {
            int wordsLeft = lineWords;
            while (wordsLeft) {
                wordsLeft--;
                cout << words[idx + lineWords - wordsLeft - 1];
                if (wordsLeft) {
                    int spacesToPrint = (int) ceil((double) spaces / (double) wordsLeft);
                    spaces -= spacesToPrint;
                    for (int i = 0; i < spacesToPrint; i++)
                        cout << ".";
                }
            }
            cout << endl;
        }
        
        idx += lineWords;
    }
    
    return 0;
}
