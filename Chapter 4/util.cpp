#include"util.h"

/*
vector<vector<int>> manually_input(std::istream &is, std::ostream &os) {
    vector<vector<int>> mat;
    vector<int> vec;
    int n = 0;
    os << "Input an square matrix of integer numbers: " << std::endl;
    int rec;
    while (is >> rec) {
        vec.push_back(rec);
    }
    int num = vec.size();
    while ((n + 1) * (n + 1) <= num)
        ++n;
    auto it = vec.begin();
    for (int i = 0; i < n; ++i) {
        mat.push_back(vector<int>());
        for (int j = 0; j < n; ++j) {
            mat[i].push_back(*it);
            ++it;
        }
    }

    return mat;
}
*/

void random_input(std::istream &is, std::ostream &os, vector<vector<int>> &a, vector<vector<int>> &b) {

    a.clear();
    b.clear();

    os << "Input the size of square matrix: " << std::endl;
    int n;
    is >> n;
    os << "Input the min and max boundary of generated integers: " << std::endl;
    int min, max;
    is >> min >> max;
    std::uniform_int_distribution<int> distribution(min, max);
    std::mt19937 generator;
    for (int i = 0; i < n; ++i) {
        a.push_back(vector<int>());
        for (int j = 0; j < n; ++j) {
            a[i].push_back(distribution(generator));
        }
    }

    for (int i = 0; i < n; ++i) {
        b.push_back(vector<int>());
        for (int j = 0; j < n; ++j) {
            b[i].push_back(distribution(generator));
        }
    }

    
    os << "Generated square matrix a: " << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            os << a[i][j] << " ";
        }
        os << endl;
    }
    os << "Generated square matrix b: " << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            os << b[i][j] << " ";
        }
        os << endl;
    }
    
}

void implement(std::function<vector<vector<int>>(const vector<vector<int>> &, const vector<vector<int>> &)> sqr_mat_mult) {
    
    vector<vector<int>> mat_a, mat_b;

    random_input(cin, cout, mat_a, mat_b);

    auto start = std::chrono::high_resolution_clock::now();

    vector<vector<int>> mat_c = sqr_mat_mult(mat_a, mat_b);

    auto end = std::chrono::high_resolution_clock::now();

    
    cout << "Output of multiplied square matrix: " << endl;

    for (auto it = mat_c.begin(); it < mat_c.end(); ++it) {
        for (auto at = (*it).begin(); at < (*it).end(); ++at) {
            cout << *at << " ";
        }
        cout << endl;
    }
    

    cout << "Size of matrix : n = " << mat_c.size() << endl;

    std::chrono::duration<double> mult_time = end - start;

    cout << "Total time taken to multiply square matrix: " << mult_time.count() << endl;
}