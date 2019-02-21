#include <bits/stdc++.h>

using namespace std;

int main() {
    int P, G, R, O, M;
    scanf("%d %d %d %d %d", &P, &G, &R, &O, &M);
    
    int combinations = 0, minTickets = M / min(min(min(P, G), R), O) + 1;
    for (int p = 0; p * P <= M; p++) {
        for (int g = 0; g * G + p * P <= M; g++) {
            for (int r = 0; r * R + g * G + p * P <= M; r++) {
                for (int o = 0; o * O + r * R + g * G + p * P <= M; o++) {
                    if (o * O + r * R + g * G + p * P == M) {
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", p, g, r, o);
                        combinations++;
                        minTickets = min(minTickets, p + g + r + o);
                    }
                }
            }
        }
    }
    
    printf("Total combinations is %d.\n", combinations);
    printf("Minimum number of tickets to print is %d.\n", minTickets);
    
    return 0;
}
