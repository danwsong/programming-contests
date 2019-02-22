#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N) {
        bool group = true;
        int G[N + 1][N + 1];

        // Input G
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                cin >> G[i][j];
        
        // Find identity
        int identity = 0;
        for (int i = 1; i <= N && !identity && group; i++) {
            bool found = true;
            for (int j = 1; j <= N && found; j++)
                if (G[i][j] != j || G[j][i] != j)
                    found = false;
            if (found)
                identity = i;
        }
        group = group && identity;

        // Check inverses
        for (int i = 1; i <= N && group; i++) {
            bool found = false;
            for (int j = 1; j <= N && !found; j++)
                if (G[i][j] == identity && G[j][i] == identity)
                    found = true;
            group = group && found;
        }

        // Check associativity
        for (int i = 1; i <= N && group; i++)
            for (int j = 1; j <= N && group; j++)
                for (int k = 1; k <= N && group; k++)
                    if (G[i][G[j][k]] != G[G[i][j]][k])
                        group = false;

        cout << (group ? "yes" : "no") << endl;

        cin >> N;
    }
    
    return 0;
}
