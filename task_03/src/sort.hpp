#pragma once

#include <iostream>
#include <vector>

using namespace std;
using iter = vector<int>::iterator;

void merge (iter left, iter mid, iter right);

void Sort1(iter left, iter right);

vector<int> Sort(vector<int>);
