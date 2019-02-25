#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string lights = "";
    for (int i = 0; i < N; i++) {
        string light;
        cin >> light;
        lights += light;
    }
    
    lights = lights.substr(lights.find_first_of('1'), lights.find_last_of('1') - lights.find_first_of('1') + 1);
    while (lights.size() < 4)
        lights += "0";

    int switched = 0;
    while (lights.find('1') != string::npos) {
        int first = lights.find_first_of('1'), left = 0;
        for (int i = first; i < lights.size() && lights[i] == '1'; i++, left++);
        int last = lights.find_last_of('1'), right = 0;
        for (int i = last; i >= 0 && lights[i] == '1'; i--, right++);

        if (left < right)
            lights[first + left] = '1';
        else if (left > right)
            lights[last - right] = '1';
        else if (first <= lights.size() - (last + 1))
            lights[first + left] = '1';
        else
            lights[last - right] = '1';

        if (lights.find("1111111") != string::npos)
            lights.replace(lights.find("1111111"), 7, "0000000");
        if (lights.find("111111") != string::npos)
            lights.replace(lights.find("111111"), 6, "000000");
        if (lights.find("11111") != string::npos)
            lights.replace(lights.find("11111"), 5, "00000");
        if (lights.find("1111") != string::npos)
            lights.replace(lights.find("1111"), 4, "0000");

        if (lights.find("1") != string::npos)
            lights = lights.substr(lights.find_first_of('1'), lights.find_last_of('1') - lights.find_first_of('1') + 1);
        while (lights.size() < 4)
            lights += "0";
        
        switched++;
    }
    cout << switched << endl;
    
    return 0;
}
