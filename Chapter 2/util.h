#pragma once

#include"common_header.h"

vector<int> manually_input(std::istream &is, std::ostream &os);
vector<int> random_input(std::istream &is, std::ostream &os);
void implement(std::function<void(vector<int> &)> sorting, std::function < vector<int>(std::istream &, std::ostream &)> input);