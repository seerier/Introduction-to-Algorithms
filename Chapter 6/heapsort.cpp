#include "heapsort.h"
#include "util.h"

void heapsort(vector<int> &vec) {
    heap h(vec);
    for (int i = vec.size() - 1; i > 0; --i) {
        int temp = vec[i];
        vec[i] = vec[0];
        vec[0] = temp;
        h.heap_size -= 1;
        h.max_heapify(0);
    }
}

void heap::max_heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l <= heap_size - 1 && nums[l] > nums[i])
            largest = l;
        if (r <= heap_size - 1 && nums[r] > nums[largest])
            largest = r;
        if (largest != i) {
            int temp = nums[i];
            nums[i] = nums[largest];
            nums[largest] = temp;
            max_heapify(largest);
        }
}

int main() {

    implement(heapsort, random_input);

    return 0;
}