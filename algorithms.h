#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

void std_sort_wrapper(std::vector<int>& data);
void qsort_wrapper(std::vector<int>& data);
void quicksort_wrapper(std::vector<int>& data);
int partition(std::vector<int>& arr, int low, int high);
void quicksort_impl(std::vector<int>& arr, int low, int high);

#endif