#ifndef MERGESORT
#define MERGESORT
#include <iostream>
#include <string>
#include <vector>
#include "util.h"

//FROM HOMEWORK 1 -- 2 Array Merge Sort
void merge_sort(std::vector<int>&, int, int);
void sorted_merge(std::vector<int>&, int, int, int);


//FOR HOMEWORK 2 -- 3 array merge sort
void merge_sort_3(std::vector<int>&, int, int);
void sorted_merge_3(std::vector<int>&, int, int, int, int);

#endif