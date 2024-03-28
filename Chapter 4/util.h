#pragma once

#include"common_header.h"

//vector<vector<int>> manually_input(std::istream &is, std::ostream &os);
void random_input(std::istream &is, std::ostream &os, vector<vector<int>> &a, vector<vector<int>> &b);
void implement(std::function<vector<vector<int>>(const vector<vector<int>> &, const vector<vector<int>> &)>);