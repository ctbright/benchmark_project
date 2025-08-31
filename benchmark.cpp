#include "benchmark.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cmath>

double BenchmarkRunner::calculate_mean(const std::vector<double>& times) {
    double sum = 0.0;
    for (double time : times) {
        sum += time;
    }
    return sum / times.size();
}

double BenchmarkRunner::calculate_std_dev(const std::vector<double>& times, double mean) {
    double variance = 0.0;
    for (double time : times) {
        variance += (time - mean) * (time - mean);
    }
    variance /= times.size();
    return std::sqrt(variance);
}

void BenchmarkRunner::print_results_table(const std::vector<BenchmarkResult>& results) {
    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "SORTING ALGORITHM BENCHMARK RESULTS" << std::endl;
    std::cout << std::string(80, '=') << std::endl;
    
    std::cout << std::left << std::setw(15) << "Algorithm"
              << std::right << std::setw(12) << "Avg (μs)"
              << std::setw(12) << "Std Dev"
              << std::setw(12) << "Min (μs)"
              << std::setw(12) << "Max (μs)"
              << std::setw(10) << "Trials" << std::endl;
    
    std::cout << std::string(80, '-') << std::endl;
    
    for (const auto& result : results) {
        std::cout << std::left << std::setw(15) << result.algorithm_name
                  << std::right << std::setw(12) << std::fixed << std::setprecision(1) << result.avg_time_us
                  << std::setw(12) << std::fixed << std::setprecision(1) << result.std_dev
                  << std::setw(12) << std::fixed << std::setprecision(1) << result.min_time
                  << std::setw(12) << std::fixed << std::setprecision(1) << result.max_time
                  << std::setw(10) << result.num_trials << std::endl;
    }
    std::cout << std::string(80, '=') << std::endl;
}

void BenchmarkRunner::export_to_csv(const std::vector<BenchmarkResult>& results, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    file << "Algorithm,Avg_Time_us,Std_Dev,Min_Time_us,Max_Time_us,Trials\n";
    for (const auto& result : results) {
        file << result.algorithm_name << ","
             << result.avg_time_us << ","
             << result.std_dev << ","
             << result.min_time << ","
             << result.max_time << ","
             << result.num_trials << "\n";
    }
    
    std::cout << "Results exported to " << filename << std::endl;
}