#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    cin >> a;
    vector<int> frequencyA(26, 0);
	int asterisks = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 'a' && a[i] <= 'z')
            frequencyA[a[i] - 'a']++;
        else
			asterisks++;
    }
    string b;
    cin >> b;
    int wildcard = 0;
    vector<int> frequencyB(26, 0);
    for (int i = 0; i < b.size(); i++) {
        if (b[i] >= 'a' && b[i] <= 'z')
            frequencyB[b[i] - 'a']++;
        else
            wildcard++;
    }
    
    for (int i = 0; i < 26; i++)
        if (frequencyB[i] < frequencyA[i])
            wildcard += frequencyB[i] - frequencyA[i] - asterisks;
    
	cout << (wildcard >= 0 ? "A" : "N") << endl;
    
    return 0;
}
