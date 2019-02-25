#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, e;
	cin >> a >> e;
    
    if (a >= 3 && e <= 4)
		cout << "TroyMartian" << endl;
    if (a <= 6 && e >= 2)
		cout << "VladSaturnian" << endl;
    if (a <= 2 && e <= 3)
		cout << "GraemeMercurian" << endl;
    
    return 0;
}
