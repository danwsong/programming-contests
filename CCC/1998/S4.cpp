#include <bits/stdc++.h>

using namespace std;

string bracket(string expression) {
    if (expression.find(" ") == string::npos)
        return expression;
    int lastAdd = expression.rfind("+");
    int lastSub = expression.rfind("-");
    int lastMul = expression.rfind("X");
    if (lastAdd == -1 && lastSub == -1) {
        expression = bracket(expression.substr(0, lastMul - 1)) + " X " + bracket(expression.substr(lastMul + 2));
    } else if (lastSub == -1 || lastAdd > lastSub) {
        expression = bracket(expression.substr(0, lastAdd - 1)) + " + " + bracket(expression.substr(lastAdd + 2));
    } else {
        expression = bracket(expression.substr(0, lastSub - 1)) + " - " + bracket(expression.substr(lastSub + 2));
    }
    return "(" + expression + ")";
}

int main() {
    int T;
    scanf("%d\n", &T);
    while (T) {
        string expression;
        getline(cin, expression);
        
        string bracketed = bracket(expression);
        if (bracketed[0] == '(')
            bracketed = bracketed.substr(1, bracketed.size() - 2);
        cout << bracketed << "\n";
        
        T--;
        printf("\n");
    }
    
    return 0;
}
