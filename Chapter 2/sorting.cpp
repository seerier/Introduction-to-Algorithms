#include "sorting.h"

void insertion_sort(vector<int> &vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void merge_sort(vector<int> &vec) {
    int n = vec.size();
    merge_sorting(vec, 0, n - 1);
}

void merge_sorting(vector<int> &vec, int p, int r) {
    if (p >= r)
        return;
    int q = (p + r) / 2;
    merge_sorting(vec, p, q);
    merge_sorting(vec, q + 1, r);
    merge(vec, p, q, r);
}

void merge(vector<int> &vec, int p, int q, int r) {
    vector<int> left, right;
    for (int i = p; i < q + 1; ++i) {
        left.push_back(vec[i]);
    }
    for (int j = q + 1; j < r + 1; ++j) {
        right.push_back(vec[j]);
    }
    int i = 0, j = 0, k = p;
    while (i < q - p + 1 && j < r - q) {
        if (left[i] <= right[j]) {
            vec[k] = left[i];
            ++i;
        }
        else {
            vec[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < q - p + 1) {
        vec[k] = left[i];
        ++i;
        ++k;
    }
    while (j < r - q) {
        vec[k] = right[j];
        ++j;
        ++k;
    }
}