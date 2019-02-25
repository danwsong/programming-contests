#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, a = 100, b = 100;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if (x < y)
			a -= y;
        if (y < x)
			b -= x;
    }
	cout << a << endl;
	cout << b << endl;
    
    return 0;
}
