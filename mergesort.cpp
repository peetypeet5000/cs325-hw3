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

    //if still in bounds (base case) if n is greather than 3
    if(end - start > 3) {
        //calculate bounds for three arrays
        first_third = start + ((end - start) / 3);
        second_third = start + (2 * ((end - start) / 3)) + 1;

        //split into three arrays
        merge_sort_3(array, start, first_third);
        merge_sort_3(array, first_third + 1, second_third);
        merge_sort_3(array, second_third + 1, end);

        //merge back together
        sorted_merge_3(array, start, first_third, second_third, end);

    } else if(end - start > 0) {
        //else, manually sort the remaining elements (base case n = 3, n = 2, n = 1)
        if(end - start == 2) { //n = 3
            if(array[start + 1] > array[start + 2]) {
                std::swap(array[start + 1], array[start + 2]);
            }
            if(array[start] > array[start + 1]) {
                std::swap(array[start], array[start + 1]);
            }
            if(array[start + 1] > array[start + 2]) {
                std::swap(array[start + 1], array[start + 2]);
            }

        } else if(end - start == 1) { //n == 2
            if(array[start] > array[start + 1]) {
                std::swap(array[start], array[start + 1]);
            }

        //if n == 1, already sorted
        }
    }

    

}




/*
 * This function takes an array, a start, and two mid points, and sorts the data in
 * ascending order. For use combining merge sort recusive calls
 * 
 *
 * Params:
 *   array - a referance to a vector containing an array of unsorted ints
 *   start - int index of where to start sorting
 *   first_third - an int of the index of the first third of the array (floor)
 *   second_third - an int of the index of the second third of the array (floor)
 *   end - an int of where you want to stop sorting (probably the array size - 1)
 */
void sorted_merge_3(std::vector<int> &array, int start, int first_third, int second_third, int end) {  
    //create temporaty arrays (copies elements inside)
    std::vector<int> a(array.begin() + start, array.begin() + first_third + 1);
    std::vector<int> b(array.begin() + (first_third + 1), array.begin() + ( second_third + 1));
    std::vector<int> c(array.begin() + (second_third + 1), array.begin() + end + 1);

    //sub array iterators
    int a_index = 0, b_index = 0, c_index = 0;

    //starting index for adding back into main array
    int curr = start;

    /*** case: all three arrays have a val ***/
    while (a_index < (int)a.size() && b_index < (int)b.size() && c_index < (int)c.size()) {
        if (a[a_index] <= b[b_index]) {
            if(a[a_index] <= c[c_index] ) {
                array[curr] = a[a_index];   //if a is smallest
                a_index++;
            } else {
                array[curr] = c[c_index]; //if c is smallest
                c_index++;
            }

        } else {    //if b less than a
            if(b[b_index] <= c[c_index]) {
                array[curr] = b[b_index];   //if b is smallest
                b_index++;
            } else {
                array[curr] = c[c_index];   //if c is smallest
                c_index++;      
            }
        }
        curr++;
    }

    /***case: first two arrays have a val ***/
    while (a_index < (int)a.size() && b_index < (int)b.size()) {
        if (a[a_index] <= b[b_index]) {
            array[curr] = a[a_index];   //a smallest
            a_index++;
        } else {
            array[curr] = b[b_index];   //b smallest
            b_index++;
        }
        curr++;
    }

    /***case: first and last arrays have a val ***/
    while (a_index < (int)a.size() && c_index < (int)c.size()) {
        if (a[a_index] <= c[c_index]) {
            array[curr] = a[a_index];   //a smallest
            a_index++;
        } else {
            array[curr] = c[c_index]; //b smallest
            c_index++;
        }
        curr++;
    }

    /***case: middle and last arrays have a val ***/
    while (b_index < (int)b.size() && c_index < (int)c.size()) {
        if (b[b_index] <= c[c_index]) {
            array[curr] = b[b_index];  //b smallest
            b_index++;
        } else {
            array[curr] = c[c_index]; //c smallest
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

    //array from start - end is now sorted


}


/************ FROM HOMEWORK 1 ****************/

/*
 * This function takes a vector of ints and sorts them in ascending order, using the
 * merge sort algorithm. Will recusivley call itsself many times
 * 
 * Complexity: Θ(nlog(n))
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
 * merge sort algorithm.
 * 
 * Complexity: Θ(n log(n))
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