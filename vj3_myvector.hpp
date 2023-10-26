#pragma once
#include <iostream>
#include <vector>
#include "vj3_myvector.hpp"
using namespace std;

#ifndef VJ3_MYVECTOR_HPP
#define VJ3_MYVECTOR_HPP

void input_vector(vector<int> &v, int elementi);
void input_in_range(vector<int> &v, int min, int max);
void print(vector<int> &v);
void compare_vector(vector<int> &myvector, vector<int> &myvector_2, vector<int> &myvector_3);

#endif // !VJ3_MYVECTOR_HPP
