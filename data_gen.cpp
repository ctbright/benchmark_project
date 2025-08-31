#include "data_gen.h"
#include <random>

std::vector<int> generate_random_data(int size) {
    std::vector<int> data;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    
    for (int i = 0; i < size; ++i) {
        data.push_back(dis(gen));
    }
    
    return data;
}

std::vector<int> generate_sorted_data(int size) {
    std::vector<int> data = generate_random_data(size);
    std::sort(data.begin(), data.end());
    return data;
}

std::vector<int> generate_reverse_sorted_data(int size) {
    std::vector<int> data = generate_random_data(size);
    std::sort(data.begin(), data.end(), std::greater<int>());
    return data;
}

std::vector<int> generate_nearly_sorted_data(int size) {
    std::vector<int> data = generate_sorted_data(size);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);
    
    int num_swaps = size / 20;  //Swaps 5% of elements
    for (int i = 0; i < num_swaps; ++i) {
        int pos1 = dis(gen);
        int pos2 = dis(gen);
        std::swap(data[pos1], data[pos2]);
    }
    
    return data;
}

std::vector<int> generate_duplicate_heavy_data(int size) {
    std::vector<int> data;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    
    for (int i = 0; i < size; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}