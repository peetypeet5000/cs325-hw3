#ifndef UTIL
#define UTIL

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <sys/time.h>

//NEW FOR HOMEWORK 3
std::vector<int> generate_array(int, int, int);

//MODIFIED FOR HOMEWORK 3
void read_file(std::vector<std::vector<int>>&);
std::vector<std::vector<int>> parse_ints(std::vector<std::string>);

//CREATED IN HOMEWORK 1 & 2
void print_array(const std::vector<std::vector<int>> &);
std::vector<int> random_numbers(int);
long int get_time_mil();


#endif


