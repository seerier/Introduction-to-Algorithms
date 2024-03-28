#include"common_header.h"
#include "util.h"

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

int main() {

    implement(insertion_sort, random_input);

    return 0;
}