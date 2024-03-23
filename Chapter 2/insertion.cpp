#include"common_header.h"

void insertion_sort(vector<int> &vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > vec[i]) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = vec[i];
    }
}

int main() {
    std::cout << "Input an array of integer numbers: " << std::endl;
    std::vector<int> vec;
    int rec;
    while (cin >> rec) {
        vec.push_back(rec);
    }
    insertion_sort(vec);

    cout << "Output of insertion sorted integer numbers: " << endl;

    for (auto it = vec.begin(); it < vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}