#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, s, h;
    cin >> t >> s >> h;
    
    for (int i = 0; i < t; i++) {
        printf("*");
        for (int j = 0; j < s; j++) {
            printf(" ");
        }
        printf("*");
        for (int j = 0; j < s; j++) {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    for (int i = 0; i < 3 + 2 * s; i++) {
        printf("*");
    }
        printf("\n");
    for (int i = 0; i < h; i++) {
        printf(" ");
        for (int i = 0; i < s; i++) {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    
    return 0;
}
