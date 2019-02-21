#include <bits/stdc++.h>

using namespace std;

int main() {
    int start, end;
    cin >> start >> end;
    
    for (; start <= end; start += 60)
        cout << "All positions change in year " << start << "\n";
    
    return 0;
}
