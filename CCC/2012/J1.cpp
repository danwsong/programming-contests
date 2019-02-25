#include <bits/stdc++.h>

using namespace std;

int main() {
    int speedLimit, speed;
	cin >> speedLimit >> speed;
    if (speed <= speedLimit)
		cout << "Congratulations, you are within the speed limit!" << endl;
    else if (speed - speedLimit <= 20)
		cout << "You are speeding and your fine is $100." << endl;
    else if (speed - speedLimit <= 30)
		cout << "You are speeding and your fine is $270." << endl;
    else
		cout << "You are speeding and your fine is $500." << endl;
    
    return 0;
}
