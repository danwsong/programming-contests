#include <bits/stdc++.h>

using namespace std;

int gcd(int u, int v) {
    return (v != 0) ? gcd(v, u % v) : u;
}

int main() {
    int num, den;
    cin >> num >> den;
    
    if (num > den)
        cout << num / den << " ";
    num -= (num / den) * den;
    if (num) {
        int common = gcd(den, num);
        num /= common;
        den /= common;
        cout << num << "/" << den;
    }
    
    return 0;
}
