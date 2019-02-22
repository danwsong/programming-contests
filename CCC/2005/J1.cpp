#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
	printf("%d%d%d", &a, &b, &c);
    
    int A = max(a - 100, 0) * 25 + b * 15 + c * 20, B = max(b - 250, 0) * 45 + b * 35 + c * 25;
    
    printf("Plan A costs %.2f\nPlan B costs %.2f\n", (float) A / 100, (float) B / 100);
    if (A < B)
		printf("Plan A is cheapest.");
    else if (A > B)
		printf("Plan B is cheapest.");
    else
		printf("Plan A and B are the same price.");
    
    return 0;
}
