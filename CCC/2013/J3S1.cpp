#include <bits/stdc++.h>

using namespace std;

vector<int> toDigits(int N) {
    vector<int> digits;
    while (N) {
        digits.push_back(N % 10);
        N /= 10;
    }
    return digits;
}

bool distinct(int N) {
    vector<int> digits = toDigits(N);
    for (int i = 0; i < digits.size(); i++)
        for (int j = i + 1; j < digits.size(); j++)
            if (digits[i] == digits[j])
                return false;
    return true;
}

int main() {
    int N;
    cin >> N;
    
    while (!distinct(++N));
    
    cout << N << endl;
    
    return 0;
}
