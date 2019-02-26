#include <bits/stdc++.h>

using namespace std;

int main() {
    int type, N;
    cin >> type >> N;
	
    vector<int> dmoj(N), peg(N);
    for (int i = 0; i < N; i++)
        cin >> dmoj[i];
    for (int i = 0; i < N; i++)
        cin >> peg[i];
    sort(dmoj.begin(), dmoj.end());
    if (type == 1)
        sort(peg.begin(), peg.end());
    else
        sort(peg.rbegin(), peg.rend());
	
    int speed = 0;
    for (int i = 0; i < N; i++)
        speed += dmoj[i] > peg[i] ? dmoj[i] : peg[i];
    cout << speed << endl;
    
    return 0;
}
