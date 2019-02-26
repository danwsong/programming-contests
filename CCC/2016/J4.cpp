#include <bits/stdc++.h>

using namespace std;

int main() {
    string time;
    cin >> time;
    int hr = (time[0] - '0') * 10 + (time[1] - '0'), min = (time[3] - '0') * 10 + (time[4] - '0');
    
    int d = 0;
    while (d < 240) {
        if ((hr >= 7 && hr < 10) || (hr >= 15 && hr < 19)) {
            d++;
        } else {
            d += 2;
        }
        min++;
        hr += min / 60;
        min %= 60;
        hr %= 24;
    }
    
    if (hr < 10) {
        cout << "0" << hr;
    } else {
        cout << hr;
    }
    cout << ":";
    if (min < 10) {
        cout << "0" << min;
    } else {
        cout << min;
    }
    cout << endl;
    
    return 0;
}
