#include <bits/stdc++.h>

using namespace std;

bool isRSA(int N) {
    int factors = 2;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            if (i * i == N)
                return false;
            factors += 2;
        }
    }
    if (factors != 4)
        return false;
    return true;
}

int main() {
    int start, end, num = 0;
    cin >> start >> end;
    for (int i = start; i <= end; i++)
        if (isRSA(i))
            num++;
    cout << "The number of RSA numbers between " << start << " and " << end << " is " << num << endl;
    
    return 0;
}
