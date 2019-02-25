#include <bits/stdc++.h>

using namespace std;

int main() {
    int B, N, Y, P;
    cin >> B >> N >> Y >> P;
    
    int ways = 0;
    for (int b = 0; b * B <= P; b++) {
        for (int n = 0; b * B + n * N <= P; n++) {
            for (int y = 0; b * B + n * N + y * Y <= P; y++) {
                if (b + n + y > 0) {
					cout << b << "Brown Trout, " << n << " Northern Pike, " << y << " Yellow Pickerel" << endl;
                    ways++;
                }
            }
        }
    }
	cout << "Number of ways to catch fish: " << ways << endl;
    
    return 0;
}
