#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    do {
        cin >> s;
        if (s == "CU") printf("see you\n");
        else if (s == ":-)") printf("I'm happy\n");
        else if (s == ":-(") printf("I'm unhappy\n");
        else if (s == ";-)") printf("wink\n");
        else if (s == ":-P") printf("stick out my tongue\n");
        else if (s == "(~.~)") printf("sleepy\n");
        else if (s == "TA") printf("totally awesome\n");
        else if (s == "CCC") printf("Canadian Computing Competition\n");
        else if (s == "CUZ") printf("because\n");
        else if (s == "TY") printf("thank-you\n");
        else if (s == "YW") printf("you're welcome\n");
        else if (s == "TTYL") printf("talk to you later\n");
        else cout << s << endl;
    } while (s != "TTYL");
    
    return 0;
}
