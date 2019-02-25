#include <bits/stdc++.h>

using namespace std;

int main() {
	int r;
	cin >> r;
    while (r) {
        int pennies = 0;
        for (int i = 1; i <= r; i++)
            pennies += (int) sqrt(r * r - i * i);
		cout << (pennies + r) * 4 + 1 << endl;
		cin >> r;
    }
}
