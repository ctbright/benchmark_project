// benchmark.h
#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <string>
#include <chrono>
#include <iostream>

template<typename SortFunction>
long long time_algorithm(const std::vector<int>& original_data, 
                        SortFunction sort_func, 
                        const std::string& name) {
    using namespace std::chrono;
    
    std::vector<int> data_copy = original_data;
    auto start = high_resolution_clock::now();
    sort_func(data_copy);
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(end - start);
    std::cout << name << ": " << duration.count() << " microseconds\n";
    
    return duration.count();
}

#endif