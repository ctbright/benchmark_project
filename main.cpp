#include <iostream>
#include <vector>
#include "algorithms.h"
#include "benchmark.h"
#include "data_gen.h"

int main() {
    const int size = 100000;
    
    std::vector<int> original_data = generate_random_data(size);
    
    BenchmarkRunner runner;
    std::vector<BenchmarkResult> results;
    
    std::cout << "Running benchmarks with " << size << " elements, 10 trials each...\n";
    
    results.push_back(runner.run_statistical_benchmark(original_data, std_sort_wrapper, "std::sort"));
    results.push_back(runner.run_statistical_benchmark(original_data, qsort_wrapper, "qsort"));
    results.push_back(runner.run_statistical_benchmark(original_data, quicksort_wrapper, "quicksort"));
    
    runner.print_results_table(results);
    runner.export_to_csv(results, "benchmark_results.csv");
    
    return 0;
}