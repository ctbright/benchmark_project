#include <iostream>
#include <vector>
#include "algorithms.h"
#include "benchmark.h"
#include "data_gen.h"

int main() {
   const int size = 100000;
   
   BenchmarkRunner runner;
   std::vector<BenchmarkResult> results;
   
   std::cout << "Running benchmarks with " << size << " elements, 10 trials each...\n";
   
   // Generate all data patterns
   auto random_data = generate_random_data(size);
   auto sorted_data = generate_sorted_data(size);
   auto reverse_data = generate_reverse_sorted_data(size);
   auto nearly_sorted_data = generate_nearly_sorted_data(size);
   auto duplicate_data = generate_duplicate_heavy_data(size);
   
   // Test each algorithm on random data
   std::cout << "\n=== RANDOM DATA ===\n";
   results.push_back(runner.run_statistical_benchmark(random_data, std_sort_wrapper, "std::sort (random)"));
   results.push_back(runner.run_statistical_benchmark(random_data, qsort_wrapper, "qsort (random)"));
   results.push_back(runner.run_statistical_benchmark(random_data, quicksort_wrapper, "quicksort (random)"));
   
   // Test each algorithm on sorted data
   std::cout << "\n=== SORTED DATA ===\n";
   results.push_back(runner.run_statistical_benchmark(sorted_data, std_sort_wrapper, "std::sort (sorted)"));
   results.push_back(runner.run_statistical_benchmark(sorted_data, qsort_wrapper, "qsort (sorted)"));
   results.push_back(runner.run_statistical_benchmark(sorted_data, quicksort_wrapper, "quicksort (sorted)"));
   
   // Test each algorithm on reverse sorted data
   std::cout << "\n=== REVERSE SORTED DATA ===\n";
   results.push_back(runner.run_statistical_benchmark(reverse_data, std_sort_wrapper, "std::sort (reverse)"));
   results.push_back(runner.run_statistical_benchmark(reverse_data, qsort_wrapper, "qsort (reverse)"));
   results.push_back(runner.run_statistical_benchmark(reverse_data, quicksort_wrapper, "quicksort (reverse)"));
   
   // Test each algorithm on nearly sorted data
   std::cout << "\n=== NEARLY SORTED DATA ===\n";
   results.push_back(runner.run_statistical_benchmark(nearly_sorted_data, std_sort_wrapper, "std::sort (nearly sorted)"));
   results.push_back(runner.run_statistical_benchmark(nearly_sorted_data, qsort_wrapper, "qsort (nearly sorted)"));
   results.push_back(runner.run_statistical_benchmark(nearly_sorted_data, quicksort_wrapper, "quicksort (nearly sorted)"));
   
   // Test each algorithm on duplicate-heavy data
   std::cout << "\n=== DUPLICATE HEAVY DATA ===\n";
   results.push_back(runner.run_statistical_benchmark(duplicate_data, std_sort_wrapper, "std::sort (duplicates)"));
   results.push_back(runner.run_statistical_benchmark(duplicate_data, qsort_wrapper, "qsort (duplicates)"));
   results.push_back(runner.run_statistical_benchmark(duplicate_data, quicksort_wrapper, "quicksort (duplicates)"));
   
   // Display all results
   runner.print_results_table(results);
   runner.export_to_csv(results, "benchmark_results.csv");
   
   return 0;
}