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