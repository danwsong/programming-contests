#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++)
			cout << "*";
        for (int j = 0; j < k; j++)
			cout << "x";
        for (int j = 0; j < k; j++)
			cout << "*";
		cout << endl;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++)
			cout << " ";
        for (int j = 0; j < k; j++)
			cout << "x";
        for (int j = 0; j < k; j++)
			cout << "x";
		cout << endl;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++)
			cout << "*";
        for (int j = 0; j < k; j++)
			cout << " ";
        for (int j = 0; j < k; j++)
			cout << "*";
		cout << endl;
    }
    
    return 0;
}
