#include <iostream>
#include <vector>
#include "algorithms.h"
#include "benchmark.h"
#include "data_gen.h"

int main() {
   BenchmarkRunner runner;
   std::vector<BenchmarkResult> results;
   
   // Test different sizes
   std::vector<int> sizes = {1000, 10000, 100000};
   
   std::cout << "Running comprehensive benchmarks across multiple sizes and data patterns...\n";
   
   for (int size : sizes) {
       std::cout << "\n" << std::string(80, '=') << std::endl;
       std::cout << "BENCHMARKING WITH " << size << " ELEMENTS (10 trials each)" << std::endl;
       std::cout << std::string(80, '=') << std::endl;
       
       // Generate all data patterns for this size
       auto random_data = generate_random_data(size);
       auto sorted_data = generate_sorted_data(size);
       auto reverse_data = generate_reverse_sorted_data(size);
       auto nearly_sorted_data = generate_nearly_sorted_data(size);
       auto duplicate_data = generate_duplicate_heavy_data(size);
       
       // Test each algorithm on random data
       std::cout << "\n=== RANDOM DATA ===\n";
       results.push_back(runner.run_statistical_benchmark(random_data, std_sort_wrapper, "std::sort (random, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(random_data, qsort_wrapper, "qsort (random, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(random_data, quicksort_wrapper, "quicksort (random, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(random_data, merge_sort_wrapper, "mergesort (random, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(random_data, heap_sort_wrapper, "heapsort (random, " + std::to_string(size) + ")"));
       
       // Test each algorithm on sorted data
       std::cout << "\n=== SORTED DATA ===\n";
       results.push_back(runner.run_statistical_benchmark(sorted_data, std_sort_wrapper, "std::sort (sorted, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(sorted_data, qsort_wrapper, "qsort (sorted, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(sorted_data, quicksort_wrapper, "quicksort (sorted, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(sorted_data, merge_sort_wrapper, "mergesort (sorted, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(sorted_data, heap_sort_wrapper, "heapsort (sorted, " + std::to_string(size) + ")"));
       
       // Test each algorithm on reverse sorted data
       std::cout << "\n=== REVERSE SORTED DATA ===\n";
       results.push_back(runner.run_statistical_benchmark(reverse_data, std_sort_wrapper, "std::sort (reverse, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(reverse_data, qsort_wrapper, "qsort (reverse, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(reverse_data, quicksort_wrapper, "quicksort (reverse, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(reverse_data, merge_sort_wrapper, "mergesort (reverse, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(reverse_data, heap_sort_wrapper, "heapsort (reverse, " + std::to_string(size) + ")"));
       
       // Test each algorithm on nearly sorted data
       std::cout << "\n=== NEARLY SORTED DATA ===\n";
       results.push_back(runner.run_statistical_benchmark(nearly_sorted_data, std_sort_wrapper, "std::sort (nearly sorted, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(nearly_sorted_data, qsort_wrapper, "qsort (nearly sorted, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(nearly_sorted_data, quicksort_wrapper, "quicksort (nearly sorted, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(nearly_sorted_data, merge_sort_wrapper, "mergesort (nearly sorted, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(nearly_sorted_data, heap_sort_wrapper, "heapsort (nearly sorted, " + std::to_string(size) + ")"));
       
       // Test each algorithm on duplicate-heavy data
       std::cout << "\n=== DUPLICATE HEAVY DATA ===\n";
       results.push_back(runner.run_statistical_benchmark(duplicate_data, std_sort_wrapper, "std::sort (duplicates, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(duplicate_data, qsort_wrapper, "qsort (duplicates, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(duplicate_data, quicksort_wrapper, "quicksort (duplicates, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(duplicate_data, merge_sort_wrapper, "mergesort (duplicates, " + std::to_string(size) + ")"));
       results.push_back(runner.run_statistical_benchmark(duplicate_data, heap_sort_wrapper, "heapsort (duplicates, " + std::to_string(size) + ")"));
   }
   
   // Display all results
   std::cout << "\n" << std::string(100, '=') << std::endl;
   std::cout << "FINAL COMPREHENSIVE RESULTS" << std::endl;
   std::cout << std::string(100, '=') << std::endl;
   
   runner.print_results_table(results);
   runner.export_to_csv(results, "comprehensive_benchmark_results.csv");
   
   return 0;
}