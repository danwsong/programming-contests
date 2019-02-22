#include <bits/stdc++.h>

using namespace std;

int N;
double inversions;

void merge(vector<int> &array, int begin, int median, int end) {
    vector<int> sorted;
    for (int x = begin, y = median + 1; x <= median || y <= end; ) {
        if (y > end || (x <= median && array[x] <= array[y])) {
            sorted.push_back(array[x++]);
        } else {
            sorted.push_back(array[y++]);
            if (x <= median)
                inversions += (median + 1 - x);
        }
    }
    for (int i = begin; i <= end; i++) {
        array[i] = sorted[i - begin];
    }
}

void mergeSort(vector<int> &array, int begin, int end) {
    if (begin < end) {
        int median = (begin + end) / 2;
        mergeSort(array, begin, median);
        mergeSort(array, median + 1, end);
        merge(array, begin, median, end);
    }
}

int main() {
    scanf("%d\n", &N);
    
    vector<int> scores(N);
    for (int i = 0; i < N; i++)
        scanf("%d\n", &scores[i]);
    inversions = (double) N;
    mergeSort(scores, 0, N - 1);
    printf("%.2lf\n", inversions / (double) N);
    
    return 0;
}
