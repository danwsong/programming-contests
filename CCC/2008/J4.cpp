#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    while (line != "0") {
        vector<string> prefix;
        for (int i = 0; i < line.size(); i += 2)
            prefix.push_back(line.substr(i, 1));
        
        stack<string> operands;
        for (int i = prefix.size() - 1; i >= 0; i--) {
            if (prefix[i] == "+" || prefix[i] == "-") {
                string op1 = operands.top();
                operands.pop();
                string op2 = operands.top();
                operands.pop();
                operands.push(op1 + " " + op2 + " " + prefix[i]);
            } else {
                operands.push(prefix[i]);
            }
        }
        
        cout << operands.top() << "\n";
        operands.pop();
        
        getline(cin, line);
    }
    
    return 0;
}
