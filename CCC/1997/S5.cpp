#include <bits/stdc++.h>

using namespace std;

string findDiff(string str1, string str2) {
    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    for (int i = 0; i < n2; i++) {
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
        
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else {
            carry = 0;
        }

        str.push_back(sub + '0');
    }

    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);

        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else {
            carry = 0;
        }

        str.push_back(sub + '0');
    } 
 
    reverse(str.begin(), str.end());

    return str;
}

int main() {
    int T;
    cin >> T;
    while (T) {
        string a, b;
        cin >> a >> b;
        
        string quotient = "";
        for (int shift = 0; shift <= (int) a.size() - (int) b.size(); shift++) {
            quotient += "0";
            string temp = b;
            while (temp.size() + shift < a.size())
                temp += '0';
            string temp2 = temp;
            while (temp2.size() < a.size())
                temp2 = '0' + temp2;
            while (a >= temp2) {
                a = findDiff(a, temp2);
                quotient[quotient.size() - 1]++;
            }
        }

        quotient.erase(0, min(quotient.find_first_not_of('0'), quotient.size() - 1));
        cout << (quotient == "" ? "0" : quotient) << "\n";
        a.erase(0, min(a.find_first_not_of('0'), a.size() - 1));
        cout << (a == "" ? "0" : a) << "\n";
        
        T--;
        cout << "\n";
    }
    
    return 0;
}
