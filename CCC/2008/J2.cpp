#include <bits/stdc++.h>

using namespace std;

int main() {
    string songs = "ABCDE";
    
    int a, b;
    do {
        cin >> a >> b;
        if (a != 4)
            for (int i = 0; i < b; i++) {
                if (a == 1) {
                    rotate(songs.begin(), songs.begin() + 1, songs.end());
                }
                if (a == 2) {
                    rotate(songs.rbegin(), songs.rbegin() + 1, songs.rend());
                }
                if (a == 3) {
                    swap(songs[0], songs[1]);
                }
            }
    } while (a != 4);
    
    for (int i = 0; i < songs.size(); i++)
        cout << songs[i] << " ";
	cout << endl;
    
    return 0;
}
