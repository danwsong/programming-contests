#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<bool> turns;
    stack<string> streets;
    
    string turn, street;
    do {
        cin >> turn >> street;
        turns.push(turn == "R");
        streets.push(street);
    } while (street != "SCHOOL");
    
    streets.pop();
    
    while (!streets.empty()) {
        cout << "Turn " << (turns.top() ? "LEFT" : "RIGHT") << " onto " << streets.top() << " street." << endl;
        turns.pop();
        streets.pop();
    }
    
    cout << "Turn " << (turns.top() ? "LEFT" : "RIGHT") << " into your HOME." << endl;
    
    return 0;
}
