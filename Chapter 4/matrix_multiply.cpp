#include "matrix_multiply.h"

vector<vector<int>> brute_sqr_mat_mult(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size();
    if (n != b.size()) {
        return vector<vector<int>>();
    }
    
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

vector<vector<int>> divide_sqr_mat_mult(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int n = a.size();
    if (n != b.size()) {
        return vector<vector<int>>();
    }
    
    vector<vector<int>> c(n, vector<int>(n, 0));

    matrix_multiply_recursive(a, b, c, n, 0, n - 1, 0, n - 1, 0, n - 1, 0, n - 1, 0, n - 1, 0, n - 1);

    return c;
}

//Stupid brute force way @_@
void matrix_multiply_recursive(const vector<vector<int>> &a, const vector<vector<int>> &b, vector<vector<int>> &c, int n,
    int a_m_begin, int a_m_end, int a_n_begin, int a_n_end,
    int b_m_begin, int b_m_end, int b_n_begin, int b_n_end,
    int c_m_begin, int c_m_end, int c_n_begin, int c_n_end) {
    if (n == 1) {
        c[c_n_begin][c_m_begin] += a[a_n_begin][a_m_begin] * b[b_n_begin][b_m_begin];
        return;
    }
    int a_m_mid = (a_m_begin + a_m_end) / 2;
    int b_m_mid = (b_m_begin + b_m_end) / 2;
    int c_m_mid = (c_m_begin + c_m_end) / 2;
    int a_n_mid = (a_n_begin + a_n_end) / 2;
    int b_n_mid = (b_n_begin + b_n_end) / 2;
    int c_n_mid = (c_n_begin + c_n_end) / 2;
    matrix_multiply_recursive(a, b, c, n / 2, a_m_begin, a_m_mid, a_n_begin, a_n_mid, b_m_begin, b_m_mid, b_n_begin, b_n_mid, c_m_begin, c_m_mid, c_n_begin, c_n_mid);
    matrix_multiply_recursive(a, b, c, n / 2, a_m_begin, a_m_mid, a_n_begin, a_n_mid, b_m_mid + 1, b_m_end, b_n_begin, b_n_mid, c_m_mid + 1, c_m_end, c_n_begin, c_n_mid);
    matrix_multiply_recursive(a, b, c, n / 2, a_m_begin, a_m_mid, a_n_mid + 1, a_n_end, b_m_begin, b_m_mid, b_n_begin, b_n_mid, c_m_begin, c_m_mid, c_n_mid + 1, c_n_end);
    matrix_multiply_recursive(a, b, c, n / 2, a_m_begin, a_m_mid, a_n_mid + 1, a_n_end, b_m_mid + 1, b_m_end, b_n_begin, b_n_mid, c_m_mid + 1, c_m_end, c_n_mid + 1, c_n_end);
    matrix_multiply_recursive(a, b, c, n / 2, a_m_mid + 1, a_m_end, a_n_begin, a_n_mid, b_m_begin, b_m_mid, b_n_mid + 1, b_n_end, c_m_begin, c_m_mid, c_n_begin, c_n_mid);
    matrix_multiply_recursive(a, b, c, n / 2, a_m_mid + 1, a_m_end, a_n_begin, a_n_mid, b_m_mid + 1, b_m_end, b_n_mid + 1, b_n_end, c_m_mid + 1, c_m_end, c_n_begin, c_n_mid);
    matrix_multiply_recursive(a, b, c, n / 2, a_m_mid + 1, a_m_end, a_n_mid + 1, a_n_end, b_m_begin, b_m_mid, b_n_mid + 1, b_n_end, c_m_begin, c_m_mid, c_n_mid + 1, c_n_end);
    matrix_multiply_recursive(a, b, c, n / 2, a_m_mid + 1, a_m_end, a_n_mid + 1, a_n_end, b_m_mid + 1, b_m_end, b_n_mid + 1, b_n_end, c_m_mid + 1, c_m_end, c_n_mid + 1, c_n_end);
}