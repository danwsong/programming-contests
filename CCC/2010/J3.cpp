#include <bits/stdc++.h>

using namespace std;

int main() {
    int vars[] = { 0, 0 };
    
    int op;
    scanf("%d", &op);
    while (op != 7) {
        char var = ' ';
        while (var != 'A' && var != 'B')
            scanf("%c", &var);
        var -= 'A';
        if (op == 1) {
            int num;
            scanf("%d", &num);
            vars[var] = num;
        } else if (op == 2) {
            printf("%d\n", vars[var]);
        } else {
            char var2 = ' ';
            while (var2 != 'A' && var2 != 'B')
                scanf("%c", &var2);
            var2 -= 'A';
            if (op == 3) {
                vars[var] = vars[var] + vars[var2];
            }
            if (op == 4) {
                vars[var] = vars[var] * vars[var2];
            }
            if (op == 5) {
                vars[var] = vars[var] - vars[var2];
            }
            if (op == 6) {
                vars[var] = vars[var] / vars[var2];
            }
        }
        scanf("%d", &op);
    }
    
    return 0;
}

