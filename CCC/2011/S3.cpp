#include <bits/stdc++.h>

using namespace std;

int solve(int m, int x, int y) {
    int squareSize = (int) pow(5, m - 1);
    int sx = x / squareSize, sy = y / squareSize;
    if (m > 1 && ((sx == 1 && sy == 1) || (sx == 2 && sy == 2) || (sx == 3 && sy == 1)))
        return solve(m - 1, x % squareSize, y % squareSize);
    return ((sx == 1 && sy == 0) || (sx == 2 && sy == 0) || (sx == 2 && sy == 1) || (sx == 3 && sy == 0));
}

int main() {
    int T;
	cin >> T;
    while (T) {
        int m, x, y;
		cin >> m >> x >> y;
        if (solve(m, x, y))
			cout << "crystal" << endl;
        else
			cout << "empty" << endl;
        T--;
    }
    
    return 0;
}
