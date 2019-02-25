#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string votes;
    cin >> N >> votes;
    
    int a = count(votes.begin(), votes.end(), 'A'), b = N - a;
    
    if (a > b)
        cout << "A" << endl;
    else if (a < b)
        cout << "B" << endl;
    else
        cout << "Tie" << endl;
    
    return 0;
}
