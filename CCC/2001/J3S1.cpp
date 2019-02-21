#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << "Cards Dealt" << " " << "Points" << endl;
    
    string hand;
    cin >> hand;
    
    vector<int> points(5, 0);
    int pointer = 0, cards = 0, total = 0;
    for (int i = 0; i < 17; i++) {
        if (hand[i] == 'C' || hand[i] == 'D' || hand[i] == 'H' || hand[i] == 'S') {
            if (cards == 0)
                points[pointer] += 3;
            if (cards == 1)
                points[pointer] += 2;
            if (cards == 2)
                points[pointer] += 1;
            if (pointer != 0)
                cout << points[pointer] << endl;
            total += points[pointer];
            pointer++;
            cards = 0;
            if (hand[i] == 'C')
                cout << "Clubs ";
            if (hand[i] == 'D')
                cout << "Diamonds ";
            if (hand[i] == 'H')
                cout << "Hearts ";
            if (hand[i] == 'S')
                cout << "Spades ";
        } else {
            cout << hand[i] << " ";
            if (hand[i] == 'A')
                points[pointer] += 4;
            if (hand[i] == 'K')
                points[pointer] += 3;
            if (hand[i] == 'Q')
                points[pointer] += 2;
            if (hand[i] == 'J')
                points[pointer] += 1;
            cards++;
        }
    }
    if (cards == 0)
        points[pointer] += 3;
    if (cards == 1)
        points[pointer] += 2;
    if (cards == 2)
        points[pointer] += 1;
    if (pointer != 0)
        cout << points[pointer] << endl;
    total += points[pointer];
    cout << "Total " << (total - 3) << endl;
    
    return 0;
}
