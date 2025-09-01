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

// Merge Sort Implementation
void merge_sort_impl(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_impl(arr, left, mid);
        merge_sort_impl(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<int> leftArr(n1), rightArr(n2);
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Wrapper for mergesort
void merge_sort_wrapper(std::vector<int>& data) {
    if (!data.empty()) {
        merge_sort_impl(data, 0, data.size() - 1);
    }
}

// Heap Sort Implementation
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

//wrapper for heap sort
void heap_sort_wrapper(std::vector<int>& data) {
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}