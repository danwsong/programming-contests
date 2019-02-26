#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> numberStack;
    
    int K;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        int currentNumber;
        cin >> currentNumber;
        
        if (currentNumber == 0) {
            numberStack.pop();
        } else {
            numberStack.push(currentNumber);
        }
    }
    
    int sum = 0;
    unsigned long size = numberStack.size();
    for (int i = 0; i < size; i++) {
        sum += numberStack.top();
        numberStack.pop();
    }
    
    cout << sum << endl;
    
    return 0;
}
