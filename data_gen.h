#ifndef DATA_GEN_H
#define DATA_GEN_H

#include <vector>

std::vector<int> generate_random_data(int size);
std::vector<int> generate_sorted_data(int size);
std::vector<int> generate_reverse_sorted_data(int size);  
std::vector<int> generate_nearly_sorted_data(int size);
std::vector<int> generate_duplicate_heavy_data(int size);

#endif