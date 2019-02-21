#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int square = 1;
    while (N) {
        if (N + square <= 100)
            square += N;
        if (square == 54) square = 19;
        if (square == 90) square = 48;
        if (square == 99) square = 77;
        if (square == 9) square = 34;
        if (square == 40) square = 64;
        if (square == 67) square = 86;
        cout << "You are now on square " << square << "\n";
        if (square == 100) {
            cout << "You Win!\n";
            break;
        }
        cin >> N;
    }
    
    if (!N) {
        cout << "You Quit!\n";
    }
    
    return 0;
}
