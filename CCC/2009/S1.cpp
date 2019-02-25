#include <bits/stdc++.h>

using namespace std;

int main() {
    int start, end;
    cin >> start >> end;
    
    int cool = 0;
    for (int i = 1; i * i * i * i * i * i <= end; i++)
		if (i * i * i * i * i * i >= start)
			cool++;
    cout << cool << endl;
    
    return 0;
}
