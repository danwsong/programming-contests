#include <bits/stdc++.h>

using namespace std;

int main() {
    int values[10] = { 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000 };
    
    int N;
    cin >> N;
    
    int sum = 1691600;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        sum -= values[a];
    }
    
    int offer;
    cin >> offer;
    offer *= (10 - N);
    
    if (offer > sum) {
        cout << "deal" << endl;
    } else {
        cout << "no deal" << endl;
    }
    
    return 0;
}
