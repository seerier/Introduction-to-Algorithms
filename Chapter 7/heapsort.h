#pragma once

#include"common_header.h"

void heapsort(vector<int> &vec);

class heap {
public:
    heap(vector<int> &vec) : nums(vec) {
        heap_size = nums.size();
        for (int i = (heap_size - 2) / 2; i >= 0; --i) {
            max_heapify(i);
        }
    }

    void max_heapify(int i);

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
    return 2 * i + 1;
    }

    int right(int i) {
    return 2 * i + 2;
    }

    vector<int> &nums;
    int heap_size;
};