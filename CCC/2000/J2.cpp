#include <bits/stdc++.h>

using namespace std;

bool valid(int N) {
    vector<int> digits;
    while (N > 0) {
        int next = N % 10;
        if (next != 0 && next != 1 && next != 8 && next != 6 && next != 9)
            return false;
        digits.push_back(next);
        N /= 10;
    }
    for (int i = 0, j = digits.size() - 1; i <= j; i++, j--) {
        if (digits[i] == digits[j] && (digits[i] == 6 || digits[i] == 9))
            return false;
        if (digits[i] != digits[j] && !((digits[i] == 6 && digits[j] == 9) || (digits[i] == 9 && digits[j] == 6)))
            return false;
    }
    return true;
}

int main() {
    int start, end;
    cin >> start >> end;
    
    int flip = 0;
    for (int i = start; i <= end; i++)
        if (valid(i))
            flip++;
            
    cout << flip << endl;
    
    return 0;
}
