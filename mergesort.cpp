#include "mergesort.h"

/*
 * This function takes a vector of ints and sorts them in ascending order, using the
 * insertion sort algorithm. Will recusivley call itsself many times
 * 
 * Complexity: Θ(log(n))
 *
 * Params:
 *   array - a referance to a vector containing an array of unsorted ints
 *   start - an int to where you want to start sorting in the array (probably 0)
 *   end - an int of where you want to stop sorting (probably the array size - 1)
 */
void merge_sort(std::vector<int> &array, int start, int end) {
    int mid_point;

    //if still in bounds (base case)
    if(start < end) {
        mid_point = (start + end) / 2;

        merge_sort(array, start, mid_point);
        merge_sort(array, mid_point + 1, end);

        sorted_merge(array, start, mid_point, end);
    }

    //else, array sorted

}




/*
 * This function takes a vector of ints and sorts them in ascending order, using the
 * insertion sort algorithm.
 * 
 * Complexity: Θ(log(n))
 *
 * Params:
 *   array - a referance to a vector containing an array of unsorted ints
 *   mid_point - an int of the middle index of the array (floor)
 *   end - an int of where you want to stop sorting (probably the array size - 1)
 */
void sorted_merge(std::vector<int> &array, int start, int mid_point, int end) {  
    //create temporaty arrays
    std::vector<int> a(array.begin() + start, array.begin() + (start + (mid_point - start + 1)));
    std::vector<int> b(array.begin() + (mid_point + 1), array.begin() + (end + 1));

    /* Merge the temp arrays */

    // iterators for both sub arrays
    int a_index = 0, b_index = 0;

    // the index we will start at when adding the subarrays back into the main array
    int curr = start;

    // compare each index of the subarrays adding the lowest value to the curr
    while (a_index < (int)a.size() && b_index < (int)b.size()) {
        if (a[a_index] <= b[b_index]) {
            array[curr] = a[a_index];
            a_index++;
        } else {
            array[curr] = b[b_index];
            b_index++;
        }
        curr++;
    }

    // copy remaining elements of a[] if any
    while (a_index < (int)a.size()) array[curr++] = a[a_index++];

    // copy remaining elements of b[] if any
    while (b_index < (int)b.size()) array[curr++] = b[b_index++];


}