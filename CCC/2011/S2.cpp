#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> a(N), b(N);
    for (int i = 0; i < N; i++)
		cin >> a[i];
    for (int i = 0; i < N; i++)
		cin >> b[i];
    
    int correct = 0;
    for (int i = 0; i < N; i++)
		if (a[i] == b[i])
			correct++;
    cout << correct << "\n";
    
    return 0;
}
