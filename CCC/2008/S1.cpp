#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<int, string>> weather;
    string city;
    int temperature;
    do {
        cin >> city >> temperature;
        weather.push_back(make_pair(temperature, city));
    } while (city != "Waterloo");
    sort(weather.begin(), weather.end());
    cout << weather[0].second << endl;
    
    return 0;
}
