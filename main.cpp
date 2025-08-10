#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include "algorithms.h"

int main() {
    using namespace std::chrono;
    
    // Create test data
    const int size = 10000;
    std::vector<int> original_data;
    
    // Fill with random numbers
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100000);
    
    for (int i = 0; i < size; ++i) {
        original_data.push_back(dis(gen));
    }
    
    // Test std::sort
    std::vector<int> data1 = original_data;  // Make copy
    auto start = high_resolution_clock::now();
    std_sort_wrapper(data1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    std::cout << "std::sort: " << duration.count() << " microseconds\n";
    
    // Test qsort
    std::vector<int> data2 = original_data;  // Make copy
    start = high_resolution_clock::now();
    qsort_wrapper(data2);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "qsort: " << duration.count() << " microseconds\n";
    
    // Test quicksort
    std::vector<int> data3 = original_data;  // Make copy
    start = high_resolution_clock::now();
    quicksort_wrapper(data3);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    std::cout << "quicksort: " << duration.count() << " microseconds\n";
    
    return 0;
}