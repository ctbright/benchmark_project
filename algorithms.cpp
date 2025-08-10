// algorithms.cpp
#include "algorithms.h"
#include <algorithm>
#include <cstdlib>

// Comparison function for qsort
int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

// Wrapper for std::sort
void std_sort_wrapper(std::vector<int>& data) {
    std::sort(data.begin(), data.end());
}

// Wrapper for C qsort
void qsort_wrapper(std::vector<int>& data) {
    qsort(data.data(), data.size(), sizeof(int), compare_ints);
}

// Simple quicksort implementation
void quicksort_impl(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort_impl(arr, low, pivot - 1);
        quicksort_impl(arr, pivot + 1, high);
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Wrapper for quicksort
void quicksort_wrapper(std::vector<int>& data) {
    if (!data.empty()) {
        quicksort_impl(data, 0, data.size() - 1);
    }
}