#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t) {
        string line;
        cin >> line;
        cout << line;
        int i = 0, n = 0;
        char cc = line[i], nc = line[i + 1];
        while (cc != '=') {
            if (cc == 'M') {
                n += 1000;
            } else if (cc == 'D') {
                n += 500;
            } else if (cc == 'C' && nc == 'M') {
                n += 900;
                i++;
            } else if (cc == 'C' && nc == 'D') {
                n += 400;
                i++;
            } else if (cc == 'C') {
                n += 100;
            } else if (cc == 'L') {
                n += 50;
            } else if (cc == 'X' && nc == 'C') {
                n += 90;
                i++;
            } else if (cc == 'X' && nc == 'L') {
                n += 40;
                i++;
            } else if (cc == 'X') {
                n += 10;
            } else if (cc == 'V') {
                n += 5;
            } else if (cc == 'I' && nc == 'X') {
                n += 9;
                i++;
            } else if (cc == 'I' && nc == 'V') {
                n += 4;
                i++;
            } else if (cc == 'I') {
                n += 1;
            }
            i++;
            cc = line[i];
            nc = line[i + 1];
        }
        while (n) {
            if (n > 1000) {
                n = 0;
                cout << "CONCORDIA CUM VERITATE";
            } else if (n == 1000) {
                n -= 1000;
                cout << "M";
            } else if (n >= 900) {
                n -= 900;
                cout << "CM";
            } else if (n >= 500) {
                n -= 500;
                cout << "D";
            } else if (n >= 400) {
                n -= 400;
                cout << "CD";
            } else if (n - 100 >= 0) {
                n -= 100;
                cout << "C";
            } else if (n >= 90) {
                n -= 90;
                cout << "XC";
            } else if (n >= 50) {
                n -= 50;
                cout << "L";
            } else if (n >= 40) {
                n -= 40;
                cout << "XL";
            } else if (n >= 10) {
                n -= 10;
                cout << "X";
            } else if (n >= 9) {
                n -= 9;
                cout << "IX";
            } else if (n >= 5) {
                n -= 5;
                cout << "V";
            } else if (n >= 4) {
                n -= 4;
                cout << "IV";
            } else {
                n -= 1;
                cout << "I";
            }
        }
        cout << "\n";

        t--;
        cout << "\n";
    }

    return 0;
}
