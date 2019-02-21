#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    while (n > 0) {
        int num;
        scanf("%d", &num);
        
        int factorSum = 1, i;
        for (i = 2; i * i < num; i++)
            if (num % i == 0)
                factorSum += i + num / i;
        if (i * i == num)
            factorSum += i;
        
        if (factorSum < num)
            printf("%d is a deficient number.\n", num);
        else if (factorSum > num)
            printf("%d is an abundant number.\n", num);
        else
            printf("%d is a perfect number.\n", num);
        
        n--;
    }
    
    return 0;
}
