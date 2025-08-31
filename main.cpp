#include <iostream>
#include <vector>
#include <random>
#include "algorithms.h"
#include "benchmark.h"

int main() {
    // Create test data
    const int size = 100000;
    std::vector<int> original_data;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    
    for (int i = 0; i < size; ++i) {
        original_data.push_back(dis(gen));
    }
    
    BenchmarkRunner runner;
    std::vector<BenchmarkResult> results;
    
    // Run statistical benchmarks
    std::cout << "Running benchmarks with " << size << " elements, 10 trials each...\n";
    
    results.push_back(runner.run_statistical_benchmark(original_data, std_sort_wrapper, "std::sort"));
    results.push_back(runner.run_statistical_benchmark(original_data, qsort_wrapper, "qsort"));
    results.push_back(runner.run_statistical_benchmark(original_data, quicksort_wrapper, "quicksort"));
    
    // Display results
    runner.print_results_table(results);
    runner.export_to_csv(results, "benchmark_results.csv");
    
    return 0;
}