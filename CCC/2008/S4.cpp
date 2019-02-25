#include <bits/stdc++.h>

using namespace std;

bool isNum(string s) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}

int evaluate(string expression[], bool &fail) {
    stack<int> nums;
    for (int i = 0; i < 7; i++) {
        if (isNum(expression[i]))
            nums.push(stoi(expression[i]));
        else {
            int op2 = nums.top();
            nums.pop();
            int op1 = nums.top();
            nums.pop();
            if (expression[i] == "+") {
                nums.push(op1 + op2);
            }
            if (expression[i] == "-") {
                nums.push(op1 - op2);
            }
            if (expression[i] == "*") {
                nums.push(op1 * op2);
            }
            if (expression[i] == "/") {
                if (op2 == 0 || op1 % op2 != 0) {
                    fail = true;
                    return 0;
                }
                nums.push(op1 / op2);
            }
        }
    }
    return nums.top();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string nums[4], ops[4] = { "+", "-", "*", "/" };
        for (int i = 0; i < 4; i++)
            cin >> nums[i];
        int maxVal = numeric_limits<int>::min();
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                if (a == b)
                    continue;
                for (int c = 0; c < 4; c++) {
                    if (c == a || c == b)
                        continue;
                    for (int d = 0; d < 4; d++) {
                        if (d == a || d == b || d == c)
                            continue;
                        for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < 4; j++) {
                                for (int k = 0; k < 4; k++) {
                                    string expression[7];
                                    bool fail;
                                    int val;
                                    fail = false;
                                    expression[0] = nums[a];
                                    expression[1] = nums[b];
                                    expression[2] = ops[i];
                                    expression[3] = nums[c];
                                    expression[4] = ops[j];
                                    expression[5] = nums[d];
                                    expression[6] = ops[k];
                                    val = evaluate(expression, fail);
                                    if (!fail && val <= 24)
                                        maxVal = max(maxVal, val);
                                    fail = false;
                                    expression[0] = nums[a];
                                    expression[1] = nums[b];
                                    expression[2] = ops[i];
                                    expression[3] = nums[c];
                                    expression[4] = nums[d];
                                    expression[5] = ops[j];
                                    expression[6] = ops[k];
                                    val = evaluate(expression, fail);
                                    if (!fail && val <= 24)
                                        maxVal = max(maxVal, val);
                                    fail = false;
                                    expression[0] = nums[a];
                                    expression[1] = nums[b];
                                    expression[2] = nums[c];
                                    expression[3] = ops[i];
                                    expression[4] = ops[j];
                                    expression[5] = nums[d];
                                    expression[6] = ops[k];
                                    val = evaluate(expression, fail);
                                    if (!fail && val <= 24)
                                        maxVal = max(maxVal, val);
                                    fail = false;
                                    expression[0] = nums[a];
                                    expression[1] = nums[b];
                                    expression[2] = nums[c];
                                    expression[3] = ops[i];
                                    expression[4] = nums[d];
                                    expression[5] = ops[j];
                                    expression[6] = ops[k];
                                    val = evaluate(expression, fail);
                                    if (!fail && val <= 24)
                                        maxVal = max(maxVal, val);
                                    fail = false;
                                    expression[0] = nums[a];
                                    expression[1] = nums[b];
                                    expression[2] = nums[c];
                                    expression[3] = nums[d];
                                    expression[4] = ops[i];
                                    expression[5] = ops[j];
                                    expression[6] = ops[k];
                                    val = evaluate(expression, fail);
                                    if (!fail && val <= 24)
                                        maxVal = max(maxVal, val);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << min(maxVal, 24) << endl;
    }
    
    return 0;
}
