#include"util.h"


vector<int> manually_input(std::istream &is, std::ostream &os) {
    vector<int> vec;
    os << "Input an vector of integer numbers: " << std::endl;
    int rec;
    while (is >> rec) {
        vec.push_back(rec);
    }
    return vec;
}

vector<int> random_input(std::istream &is, std::ostream &os) {
    vector<int> vec;
    os << "Input the size of vector: " << std::endl;
    int n;
    is >> n;
    os << "Input the min and max boundary of generated integers: " << std::endl;
    int min, max;
    is >> min >> max;
    std::uniform_int_distribution<int> distribution(min, max);
    std::mt19937 generator;
    for (int i = 0; i < n; ++i) {
        vec.push_back(distribution(generator));
    }
    os << "Generated numbers: " << std::endl;
    for (int i = 0; i < n; ++i) {
        os << vec[i] << " ";
    }
    os << std::endl;
    return vec;
}

void implement(std::function<void(vector<int> &)> sorting, std::function < vector<int>(std::istream &, std::ostream &)> input) {
    vector<int> vec = input(cin, cout);

    auto start = std::chrono::high_resolution_clock::now();

    sorting(vec);

    auto end = std::chrono::high_resolution_clock::now();

    cout << "Output of sorted integer numbers: " << endl;

    for (auto it = vec.begin(); it < vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Numbers being sorted : n = " << vec.size() << endl;

    std::chrono::duration<double> sort_time = end - start;

    cout << "Total time taken to sort: " << sort_time.count() << endl;
}