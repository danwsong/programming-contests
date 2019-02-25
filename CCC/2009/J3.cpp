#include <bits/stdc++.h>

using namespace std;

int main() {
    int time;
    cin >> time;
    
    int hr = time / 100, min = time % 100;
    
    cout << time << " in Ottawa" << endl;
    cout << (((hr + 21) % 24) * 100 + min) << " in Victoria" << endl;
    cout << (((hr + 22) % 24) * 100 + min) << " in Edmonton" << endl;
    cout << (((hr + 23) % 24) * 100 + min) << " in Winnipeg" << endl;
    cout << time << " in Toronto" << endl;
    cout << (((hr + 1) % 24) * 100 + min) << " in Halifax" << endl;
    cout << (((hr + 1 + (min + 30) / 60) % 24) * 100 + (min + 30) % 60) << " in St. John's" << endl;
    
    return 0;
}
