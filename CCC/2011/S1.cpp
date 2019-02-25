#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        
        sum += count(s.begin(), s.end(), 's');
        sum += count(s.begin(), s.end(), 'S');
        sum -= count(s.begin(), s.end(), 't');
        sum -= count(s.begin(), s.end(), 'T');
    }
    
    if (sum < 0)
		cout << "English" << endl;
    else
		cout << "French" << endl;
    
    return 0;
}
