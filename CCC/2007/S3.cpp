#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    int friends[10000];
    for (int i = 0; i < 10000; i++)
        friends[i] = -1;
    
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        friends[a] = b;
    }
    
    int a, b;
    bool visited[10000];
    do {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            break;
        for (int i = 0; i < 10000; i++)
            visited[i] = false;
        int next = a, dist = 0;
        while (!visited[next]) {
            visited[next] = true;
            if (next == b)
                break;
            next = friends[next];
            dist++;
        }
        if (visited[b]) {
            printf("Yes %d\n", dist - 1);
        else
            printf("No\n");
    } while (true);
    
    return 0;
}
