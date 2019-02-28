#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Q;
vector<int> lineAtStation, stationPosOnLine, ridersAtStation, lineSize, rangeSum, lineShift;
vector< vector<int> > stationsOnLine, lastStation;

inline int val(int station) {
    return ridersAtStation[stationsOnLine[lineAtStation[station]][(stationPosOnLine[station] + lineShift[lineAtStation[station]]) % lineSize[lineAtStation[station]]]];
}

int main(int argc, char * argv[]) {
    cin >> N >> M >> Q;
    
    lineAtStation = vector<int>(N + 1);
    lineSize = vector<int>(N + 1);
    stationPosOnLine = vector<int>(N + 1);
    stationsOnLine = vector< vector<int> >(M + 1);
    lastStation = vector< vector<int> >(M + 1, vector<int>(400, -1));
    for (int station = 1; station <= N; station++) {
        cin >> lineAtStation[station];
        stationsOnLine[lineAtStation[station]].push_back(station);
        lineSize[lineAtStation[station]]++;
        stationPosOnLine[station] = lineSize[lineAtStation[station]] - 1;
        lastStation[lineAtStation[station]][station / 400] = station;
    }
    ridersAtStation = vector<int>(N + 1);
    rangeSum = vector<int>(N / 400 + 1);
    for (int i = 1; i <= N; i++) {
        cin >> ridersAtStation[i];
        rangeSum[i / 400] += ridersAtStation[i];
    }
    
    lineShift = vector<int>(M + 1);
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            int result = 0;
            for (; l % 400 && l <= r; l++)
                result += val(l);
            for (; l + 400 <= r; l += 400)
                result += rangeSum[l / 400];
            for (; l <= r; l++)
                result += val(l);
            cout << result << endl;
        } else {
            int line;
            cin >> line;
            int beginning = -1, previous = 0;
            for (int j = 0; j < 400; j++) {
                if (lastStation[line][j] == -1)
                    continue;
                if (beginning == -1)
                    beginning = j;
                rangeSum[j] += previous;
                previous = val(lastStation[line][j]);
                rangeSum[j] -= previous;
            }
            rangeSum[beginning] += previous;
            lineShift[line] = (lineShift[line] + lineSize[line] - 1) % lineSize[line];
        }
    }
    
    return 0;
}