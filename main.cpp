#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include "algorithms.h"
#include "benchmark.h"

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
    
    time_algorithm(original_data, std_sort_wrapper, "std::sort");
    time_algorithm(original_data, qsort_wrapper, "qsort");
    time_algorithm(original_data, quicksort_wrapper, "quicksort");
    
    return 0;
}