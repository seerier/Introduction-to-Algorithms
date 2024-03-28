#include"common_header.h"
#include "util.h"
#include "quicksort.h"

void quicksort(vector<int> &vec) {
    quick_sorting(vec, 0, vec.size() - 1);
}

void quick_sorting(vector<int> &vec, int p, int r) {
    if (p < r) {
        int q = partition(vec, p, r);
        quick_sorting(vec, p, q - 1);
        quick_sorting(vec, q + 1, r);
    }
}

int partition(vector<int> &vec, int p, int r) {
    int x = vec[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (vec[j] < vec[r]) {
            ++i;
            exchange(vec[j], vec[i]);
        }
    }
    ++i;
    exchange(vec[i], vec[r]);
    return i;
}

int main() {

    implement(quicksort, random_input);

    return 0;
}