#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t) {
        string number;
        cin >> number;
        cout << number << "\n";
        
        vector<int> digits(number.size());
        
        for (int i = 0; i < number.size(); i++)
            digits[i] = number[i] - '0';
     
        int lastDigit = number.size();
        while ((digits[0] != 0 && lastDigit > 2) || (digits[0] == 0 && lastDigit > 3)) {
            lastDigit--;
            if (digits[lastDigit] <= digits[lastDigit - 1]) {
                digits[lastDigit - 1] -= digits[lastDigit]; 
            } else {
                digits[lastDigit - 1] = digits[lastDigit - 1] - digits[lastDigit] + 10;
                int j = lastDigit - 2;
                while (!digits[j])
                    digits[j--] = 9;
                digits[j]--;
            }
            if (digits[0])
                cout << digits[0];
            for (int j = 1; j < lastDigit; j++)
                cout << digits[j];
            cout << "\n";
        }
        
        cout << "The number " << number;
        if (!((digits[0] == 0 && lastDigit == 2)) && ((digits[0] != 0 && ((digits[0] * 10 + digits[1]) % 11 == 0)) || (digits[0] == 0 && ((digits[1] * 10 + digits[2]) % 11 == 0))))
            cout << " is divisible by 11.\n";
        else
            cout << " is not divisible by 11.\n";
        
        t--;
        cout << "\n";
    }
    
    return 0;
}
