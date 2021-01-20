#include "mergesort.h"

/*
 * This function takes a vector of ints and sorts them in ascending order, using the
 * insertion sort algorithm. Will recusivley call itsself many times. Some code resued from
 * my Homework 1
 * 
 * Complexity: Θ(log(n))
 *
 * Params:
 *   array - a referance to a vector containing an array of unsorted ints
 *   start - an int to where you want to start sorting in the array (probably 0)
 *   end - an int of where you want to stop sorting (probably the array size - 1)
 */
void merge_sort_3(std::vector<int> &array, int start, int end) {
    int first_third, second_third;

    //if still in bounds (base case)
    if(start < end) {
        first_third = start + ((end - start) / 3);
        second_third = start + (2 * ((end - start) / 3)) + 1;

        merge_sort_3(array, start, first_third);
        merge_sort_3(array, first_third + 1, second_third);
        merge_sort_3(array, second_third + 1, end);

        sorted_merge(array, start, first_third, second_third, end);
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
void sorted_merge(std::vector<int> &array, int start, int first_third, int second_third, int end) {  
    //create temporaty arrays
    std::vector<int> a(array.begin() + start, array.begin() + (start + (first_third - start + 1)));
    std::vector<int> b(array.begin() + (first_third + 1), array.begin() + (second_third - first_third + 1));
    std::vector<int> c(array.begin() + (second_third + 1), array.begin() + (end + 1));

    // iterators for both sub arrays
    int a_index = 0, b_index = 0, c_index = 0;

    // the index we will start at when adding the subarrays back into the main array
    int curr = start;

    /*** case: all three arrays have a val ***/
    while (a_index < (int)a.size() && b_index < (int)b.size() && c_index < (int)c.size()) {
        if (a[a_index] <= b[b_index]) {
            if(a[a_index] <= c[b_index] ) {
                array[curr] = a[a_index];
                a_index++;
            } else {
                array[curr] = c[a_index];
                c_index++;
            }

        } else {    //if b less than a
            if(b[b_index] <= c[c_index]) {
                array[curr] = b[b_index];
                b_index++;
            } else {
                array[curr] = c[b_index];
                c_index++;      
            }
        }
        curr++;
    }

    /***case: first two arrays have a val ***/
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

    /***case: first and last arrays have a val ***/
    while (a_index < (int)a.size() && c_index < (int)c.size()) {
        if (a[a_index] <= c[c_index]) {
            array[curr] = a[a_index];
            a_index++;
        } else {
            array[curr] = c[c_index];
            c_index++;
        }
        curr++;
    }

    /***case: middle and last arrays have a val ***/
    while (b_index < (int)b.size() && c_index < (int)c.size()) {
        if (b[b_index] <= c[c_index]) {
            array[curr] = b[b_index];
            b_index++;
        } else {
            array[curr] = c[c_index];
            c_index++;
        }
        curr++;
    }
    
    /*** case: only 1 array has a val ***/
    // copy remaining elements of a[] if any
    while (a_index < (int)a.size()) {
         array[curr++] = a[a_index++];
    }

    // copy remaining elements of b[] if any
    while (b_index < (int)b.size()) {
        array[curr++] = b[b_index++];
    }

    // copy remaining elements of c[] if any
    while (c_index < (int)c.size()){
         array[curr++] = c[c_index++];
    }


}