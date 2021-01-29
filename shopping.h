#ifndef SHOP
#define SHOP

#include "util.h"

void shopping_spree(std::vector<std::vector<int>>&, const int, int&);
void read_data(int&, int&, int&, int&, std::vector<int>&, std::vector<int>&, std::vector<int>&, std::vector<std::vector<int>>&, const int);
void print_input_data(const std::vector<int>&, const std::vector<int>&, const std::vector<int>&, const int, const int, const int);
void print_result(const std::vector<int>&, const std::vector<int>&, const std::vector<int>&, const std::vector<std::vector<int>>&, const int, const int, const int);
int get_max_capacity(int, std::vector<int>&);
std::vector<std::vector<int>> dp_generate_array(const std::vector<int>&, const std::vector<int>&, int, int);
std::vector<int> backtrace_family(const std::vector<std::vector<int>>&, const std::vector<int>&, const std::vector<int>&, int, int, int&);

#endif
