#include "mergeTime.h"

/*
 * This program will output timing data merge sorting arrays of ints of various sizes
 */
int main() {
    srand(time(NULL));

    for(int n = 10000; n < 200001; n = n + 10000) {
        std::vector<int> data = random_numbers(n);

        long int start_time = get_time_mil();

        merge_sort(data, 0, (data.size() - 1));

        long int end_time = get_time_mil();

        std::cout << "\nMerge sorted n=" << n << " elements in " << end_time - start_time << " ms.";

    }
    
    std::cout << "\n";
}
