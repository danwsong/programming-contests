#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    getline(cin, a);
    
    int happy = 0, sad = 0;
    for (int i = a.find(":-)"); i != string::npos; i = a.find(":-)", i + 3))
		happy++;
    for (int i = a.find(":-("); i != string::npos; i = a.find(":-(", i + 3))
		sad++;
    
    if (happy == 0 && sad == 0)
		cout << "none";
    else if (happy > sad)
		cout << "happy";
    else if (happy < sad)
		cout << "sad";
    else
		cout << "unsure";
    
    return 0;
}
