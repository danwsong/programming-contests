#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
    scanf("%d\n", &T);
    while (T) {
        int A, B, C;
        scanf("%d %d %d\n", &A, &B, &C);
        
        vector<string> subjects(A), verbs(B), objects(C);
        for (int i = 0; i < A; i++)
            getline(cin, subjects[i]);
        for (int j = 0; j < B; j++)
            getline(cin, verbs[j]);
        for (int k = 0; k < C; k++)
            getline(cin, objects[k]);
        
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                for (int k = 0; k < C; k++)
                    cout << subjects[i] << " " << verbs[j] << " " << objects[k] << ".\n";
        
        T--;
    }
    
    return 0;
}
