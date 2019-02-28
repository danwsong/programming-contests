#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string a, b;
    cin >> a >> b;
    
    int counter = 0;
    for (int i = 0; i < N; i++)
        if (a[i] == 'C' && b[i] == 'C')
            counter++;
    cout << counter << endl;
    
    return 0;
}