#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, h, cw, ch, steps;
    cin >> w >> h >> cw >> ch >> steps;
    
    int r = 0, c = cw;
    
    int w1 = w - 2 * cw - 1, h1 = ch, w2 = cw, h2 = h - 2 * ch - 1;
    int saveSteps = steps;
    while (steps) {
        for (int i = 0; i < w1 && steps; i++, steps--, c++);
        for (int i = 0; i < h1 && steps; i++, steps--, r++);
        for (int i = 0; i < w2 && steps; i++, steps--, c++);
        if (!h2)
            break;
        for (int i = 0; i < h2 && steps; i++, steps--, r++);
        for (int i = 0; i < w2 && steps; i++, steps--, c--);
        for (int i = 0; i < h1 && steps; i++, steps--, r++);
        if (!w1)
            break;
        for (int i = 0; i < w1 && steps; i++, steps--, c--);
        for (int i = 0; i < h1 && steps; i++, steps--, r--);
        for (int i = 0; i < w2 && steps; i++, steps--, c--);
        if (!h2)
            break;
        for (int i = 0; i < h2 && steps; i++, steps--, r--);
        for (int i = 0; i < w2 && steps; i++, steps--, c++);
        for (int i = 0; i < h1 - 1 && steps; i++, steps--, r--);
        for (int i = 0; i < 1 && steps; i++, steps--, c++);
        w1 -= 2;
        h2 -= 2;
    }
    
    cout << (c + 1) << endl;
    cout << (r + 1) << endl;
    
    return 0;
}
