#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <string>
#include <functional>

struct BenchmarkResult {
    std::string algorithm_name;
    double avg_time_us;
    double std_dev;
    double min_time;
    double max_time;
    int num_trials;
};

class BenchmarkRunner {
private:
    static const int DEFAULT_TRIALS = 10;
    
    double calculate_mean(const std::vector<double>& times);
    double calculate_std_dev(const std::vector<double>& times, double mean);
    
public:
    template<typename SortFunction>
    BenchmarkResult run_statistical_benchmark(const std::vector<int>& original_data,
                                            SortFunction sort_func,
                                            const std::string& name,
                                            int trials = DEFAULT_TRIALS);
    
    void print_results_table(const std::vector<BenchmarkResult>& results);
    void export_to_csv(const std::vector<BenchmarkResult>& results, const std::string& filename);
};

// Template implementation (must be in header)
template<typename SortFunction>
BenchmarkResult BenchmarkRunner::run_statistical_benchmark(const std::vector<int>& original_data,
                                                          SortFunction sort_func,
                                                          const std::string& name,
                                                          int trials) {
    using namespace std::chrono;
    std::vector<double> times;
    
    for (int i = 0; i < trials; ++i) {
        std::vector<int> data_copy = original_data;
        auto start = high_resolution_clock::now();
        sort_func(data_copy);
        auto end = high_resolution_clock::now();
        
        double duration = duration_cast<microseconds>(end - start).count();
        times.push_back(duration);
    }
    
    double mean = calculate_mean(times);
    double std_dev = calculate_std_dev(times, mean);
    double min_time = *std::min_element(times.begin(), times.end());
    double max_time = *std::max_element(times.begin(), times.end());
    
    return {name, mean, std_dev, min_time, max_time, trials};
}

#endif