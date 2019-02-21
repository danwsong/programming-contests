#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T) {
        int x = 0, y = 0, dir = 0;
        
        int op;
        cin >> op;
        while (op) {
            if (op == 1) {
                int d;
                cin >> d;
                if (dir == 0) {
                    x += d;
                }
                if (dir == 1) {
                    y += d;
                }
                if (dir == 2) {
                    x -= d;
                }
                if (dir == 3) {
                    y -= d;
                }
            }
            if (op == 2) {
                dir -= 1;
                if (dir < 0)
                    dir += 4;
            }
            if (op == 3) {
                dir += 1;
                if (dir >= 4)
                    dir -= 4;
            }
            
            cin >> op;
        }
        
        cout << "Distance is " << (abs(x) + abs(y)) << "\n";
        
        if (x > 0 && y > 0 && dir == 0) {
            cout << "2\n1\n" << abs(y) << "\n2\n1\n" << abs(x) << "\n";
        }
        if (x > 0 && y > 0 && dir == 1) {
            cout << "3\n1\n" << abs(x) << "\n3\n1\n" << abs(y) << "\n";
        }
        if (x > 0 && y > 0 && dir == 2) {
            cout << "1\n" << abs(x) << "\n3\n1\n" << abs(y) << "\n";
        }
        if (x > 0 && y > 0 && dir == 3) {
            cout << "1\n" << abs(y) << "\n2\n1\n" << abs(x) << "\n";
        }
        if (x < 0 && y > 0 && dir == 0) {
            cout << "1\n" << abs(x) << "\n2\n1\n" << abs(y) << "\n";
        }
        if (x < 0 && y > 0 && dir == 1) {
            cout << "2\n1\n" << abs(x) << "\n2\n1\n" << abs(y) << "\n";
        }
        if (x < 0 && y > 0 && dir == 2) {
            cout << "3\n1\n" << abs(y) << "\n3\n1\n" << abs(x) << "\n";
        }
        if (x < 0 && y > 0 && dir == 3) {
            cout << "1\n" << abs(y) << "\n3\n1\n" << abs(x) << "\n";
        }
        if (x < 0 && y < 0 && dir == 0) {
            cout << "1\n" << abs(x) << "\n3\n1\n" << abs(y) << "\n";
        }
        if (x < 0 && y < 0 && dir == 1) {
            cout << "1\n" << abs(y) << "\n2\n1\n" << abs(x) << "\n";
        }
        if (x < 0 && y < 0 && dir == 2) {
            cout << "2\n1\n" << abs(y) << "\n2\n1\n" << abs(x) << "\n";
        }
        if (x < 0 && y < 0 && dir == 3) {
            cout << "3\n1\n" << abs(x) << "\n3\n1\n" << abs(y) << "\n";
        }
        if (x > 0 && y < 0 && dir == 0) {
            cout << "3\n1\n" << abs(y) << "\n3\n1\n" << abs(x) << "\n";
        }
        if (x > 0 && y < 0 && dir == 1) {
            cout << "1\n" << abs(y) << "\n3\n1\n" << abs(x) << "\n";
        }
        if (x > 0 && y < 0 && dir == 2) {
            cout << "1\n" << abs(x) << "\n2\n1\n" << abs(y) << "\n";
        }
        if (x > 0 && y < 0 && dir == 3) {
            cout << "2\n1\n" << abs(x) << "\n2\n1\n" << abs(y) << "\n";
        }
        if (x > 0 && y == 0 && dir == 0) {
            cout << "2\n2\n1\n" << abs(x) << "\n";
        }
        if (x > 0 && y == 0 && dir == 1) {
            cout << "3\n1\n" << abs(x) << "\n";
        }
        if (x > 0 && y == 0 && dir == 2) {
            cout << "1\n" << abs(x) << "\n";
        }
        if (x > 0 && y == 0 && dir == 3) {
            cout << "2\n1\n" << abs(x) << "\n";
        }
        if (x == 0 && y > 0 && dir == 0) {
            cout << "2\n1\n" << abs(y) << "\n";
        }
        if (x == 0 && y > 0 && dir == 1) {
            cout << "3\n3\n1\n" << abs(y) << "\n";
        }
        if (x == 0 && y > 0 && dir == 2) {
            cout << "3\n1\n" << abs(y) << "\n";
        }
        if (x == 0 && y > 0 && dir == 3) {
            cout << "1\n" << abs(y) << "\n";
        }
        if (x < 0 && y == 0 && dir == 0) {
            cout << "1\n" << abs(x) << "\n";
        }
        if (x < 0 && y == 0 && dir == 1) {
            cout << "2\n1\n" << abs(x) << "\n";
        }
        if (x < 0 && y == 0 && dir == 2) {
            cout << "3\n3\n1\n" << abs(x) << "\n";
        }
        if (x < 0 && y == 0 && dir == 3) {
            cout << "3\n1\n" << abs(x) << "\n";
        }
        if (x == 0 && y < 0 && dir == 0) {
            cout << "3\n1\n" << abs(y) << "\n";
        }
        if (x == 0 && y < 0 && dir == 1) {
            cout << "1\n" << abs(y) << "\n";
        }
        if (x == 0 && y < 0 && dir == 2) {
            cout << "2\n1\n" << abs(y) << "\n";
        }
        if (x == 0 && y < 0 && dir == 3) {
            cout << "3\n3\n1\n" << abs(y) << "\n";
        }
        
        T--;
        cout << "\n";
    }
    
    return 0;
}
