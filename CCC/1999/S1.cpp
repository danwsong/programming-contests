#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 0, b = 0;
    vector<string> cards(52);
    for (int c = 0; c < 52; c++) {
        cin >> cards[c];
    }
    
    for (int c = 0; c < 52; c++) {
        if (c < 51 && cards[c] == "jack") {
            bool check = false;
            for (int i = 1; i <= 1; i++)
                if (cards[c + i] == "jack" || cards[c + i] == "queen" || cards[c + i] == "king" || cards[c + i] == "ace")
                    check = true;
            if (!check) {
                if (c % 2 == 0)
                    a++;
                else
                    b++;
                cout << "Player " << ((c % 2 == 0) ? 'A' : 'B') << " scores " << 1 << " point(s).\n";
            }
        }
        if (c < 50 && cards[c] == "queen") {
            bool check = false;
            for (int i = 1; i <= 2; i++)
                if (cards[c + i] == "jack" || cards[c + i] == "queen" || cards[c + i] == "king" || cards[c + i] == "ace")
                    check = true;
            if (!check) {
                if (c % 2 == 0)
                    a += 2;
                else
                    b += 2;
                cout << "Player " << ((c % 2 == 0) ? 'A' : 'B') << " scores " << 2 << " point(s).\n";
            }
        }
        if (c < 49 && cards[c] == "king") {
            bool check = false;
            for (int i = 1; i <= 3; i++)
                if (cards[c + i] == "jack" || cards[c + i] == "queen" || cards[c + i] == "king" || cards[c + i] == "ace")
                    check = true;
            if (!check) {
                if (c % 2 == 0)
                    a += 3;
                else
                    b += 3;
                cout << "Player " << ((c % 2 == 0) ? 'A' : 'B') << " scores " << 3 << " point(s).\n";
            }
        }
        if (c < 48 && cards[c] == "ace") {
            bool check = false;
            for (int i = 1; i <= 4; i++)
                if (cards[c + i] == "jack" || cards[c + i] == "queen" || cards[c + i] == "king" || cards[c + i] == "ace")
                    check = true;
            if (!check) {
                if (c % 2 == 0)
                    a += 4;
                else
                    b += 4;
                cout << "Player " << ((c % 2 == 0) ? 'A' : 'B') << " scores " << 4 << " point(s).\n";
            }
        }
    }
    
    cout << "Player A: " << a << " point(s).\n";
    cout << "Player B: " << b << " point(s).\n";
    
    return 0;
}
