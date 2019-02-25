#include <bits/stdc++.h>

using namespace std;

int main() {
    double weight, height;
    
	cin >> weight >> height;
    
    double bmi = weight / (height * height);
    
    if (bmi > 25)
        printf("Overweight\n");
    else if (bmi < 18.5)
        printf("Underweight\n");
    else
        printf("Normal weight\n");
    
    return 0;
}
