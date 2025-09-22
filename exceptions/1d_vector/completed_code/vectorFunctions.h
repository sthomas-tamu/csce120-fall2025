// header guards
#ifndef VECTORFUNCTIONS_H
#define VECTORFUNCTIONS_H

#include <vector>
//best practice to not have using statements in header files as these get propagated

void print(const std::vector<int>& v);

void loadRandom(std::vector<int>& v, unsigned int size);

int getMax(const std::vector<int>& v);
int getMin(const std::vector<int>& v);

unsigned int countVal(int val, const std::vector<int>& v);

#endif

