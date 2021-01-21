#include "mergesort3Time.h"

/*
 * This program will output timing data merge sorting arrays of ints of various sizes.
 * Reuses some code from my Homework 1
 */
int main() {
    srand(time(NULL));

    /* Run HW 1 mergesort2 test for comparision */
    std::cout << "*** MergeSort2 Test: ***";

    for(int n = 25000; n < 500001; n = n + 25000) {
        std::vector<int> data = random_numbers(n);

        long int start_time = get_time_mil();

        merge_sort(data, 0, (data.size() - 1));

        long int end_time = get_time_mil();

        std::cout << "\nmergesort2 sorted n=" << n << " elements in " << end_time - start_time << " ms.";

    }

    
    /* Run HW 2 mergesort3 test */
    std::cout << "\n\n*** MergeSort3 Test: ***";

    for(int n = 25000; n < 500001; n = n + 25000) {
        std::vector<int> data = random_numbers(n);

        long int start_time = get_time_mil();

        merge_sort_3(data, 0, (data.size() - 1));

        long int end_time = get_time_mil();

        std::cout << "\nmergesort3 sorted n=" << n << " elements in " << end_time - start_time << " ms.";

    }
    


    std::cout << "\n";
}
