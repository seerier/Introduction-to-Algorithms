#pragma once

#include "common_header.h"

vector<vector<int>> brute_sqr_mat_mult(const vector<vector<int>> &a, const vector<vector<int>> &b);

vector<vector<int>> divide_sqr_mat_mult(const vector<vector<int>> &a, const vector<vector<int>> &b);

void matrix_multiply_recursive(const vector<vector<int>> &a, const vector<vector<int>> &b, vector<vector<int>> &c, int n,
    int a_m_begin, int a_m_end, int a_n_begin, int a_n_end,
    int b_m_begin, int b_m_end, int b_n_begin, int b_n_end,
    int c_m_begin, int c_m_end, int c_n_begin, int c_n_end);