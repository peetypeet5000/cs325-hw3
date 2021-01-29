#include "shopping.h"

using std::vector;
using std::cout;



int main() {

    //get data from "shopping.txt"
    vector<vector<int>> data;
    read_file(data);

    int line_in_file = 1;   //skip first line

    //T Test Cases  (first int in file)
    for(int i = 0; i < data[0][0]; i++) {
        //call for each case
        shopping_spree(data, i, line_in_file);
    }

}



/*
 *  Driver file for shopping spree. Declares all variables, runs the DP algo, runs
 *  the backtracing, finds the value of all the items that were backtraced, and then
 *  prints results to file
 * 
 *  Params:
 *    data - the 2D vector of ints from "shopping.txt"
 *    test_case - an int corresponing to which test case this is,
 *       just used for printing to output
 *    line_in_file - referanced int for use keeping track of what line we are
 *       at in the input file 
 *
 */
void shopping_spree(vector<vector<int>>& data, const int test_case, int& line_in_file) {
        //Declare and read-in data from file
        int num_items, num_people;
        int max_capacity = 0;
        vector<int> prices, weights, people_capacity;
        read_data(num_items, num_people, line_in_file, max_capacity, prices, weights, people_capacity, data, test_case);

        //Run Algorithm for max weight & save result
        vector<vector<int>> dp_result = dp_generate_array(prices, weights, max_capacity, num_items);

        //backtrace to get each family members result & the total price
        vector<vector<int>> items_taken;
        int total_price = 0;
        for(int i = 0; i < num_people; i++) {
            items_taken.push_back(backtrace_family(dp_result, prices, weights, people_capacity[i], num_items, total_price));
        }
        

        //print result
        print_result(prices, weights, people_capacity, items_taken, num_items, num_people, total_price, test_case);

}



/*
 *  Parses the 2D vector of ints from "shopping.txt" into the various variables 
 *  used by the algorithm. passes all by referance as they are created earlier
 *  in the program.
 */
void read_data(int& num_items, int& num_people, int& line_in_file, int& max_capacity, vector<int>& prices, vector<int>& weights, vector<int>& people_capacity, vector<vector<int>>& data, const int i) {
        //get all prices and weights into arrays
        num_items = data[line_in_file++][0];
        for(int n = 0; n < num_items; n++) {
            prices.push_back(data[line_in_file][0]);
            weights.push_back(data[line_in_file][1]);
            line_in_file++;
        }

        //get all family member capacity values in array
        num_people = data[line_in_file++][0];
        for(int n = 0; n < num_people; n++) {
            people_capacity.push_back(data[line_in_file][0]);
            //keep track of whateve the highest capacity is
            if(max_capacity < data[line_in_file][0]) {
                max_capacity = data[line_in_file][0];
            }
            line_in_file++;
        }

        //uncomment for testing purposes
        //print_input_data(prices, weights, people_capacity, num_items, num_people, i);

}



/*
 *  Prints the data read in to "results.txt"
 *
 */
void print_input_data(const vector<int>& prices, const vector<int>& weights, const vector<int>& people_capacity, const int num_items, const int num_people, const int test_case) {
    //open the file in append mode
    std::ofstream output_file;
    output_file.open("results.txt", std::ios::app);

    /* Print Data for Testing */
    output_file << "\n\n***Test Case: " << test_case + 1 << "***\nNumber of Items: " << num_items << "\nNumber of People: " << num_people;

    for(int i = 0; i < num_items; i++) {
        output_file << "\nItem: " << i + 1 << " Price: " << prices[i] << " Weight: " << weights[i];
    }
    for(int i = 0; i < num_people; i++) {
        output_file << "\nPerson: " << i + 1 << " Capacity: " << people_capacity[i];
    }

    output_file.close();
}



/*
 *  Prints the results of the algorithm to "results.txt"
 *
 */
void print_result(const vector<int>& prices, const vector<int>& weights, const vector<int>& people_capacity, const vector<vector<int>>& items_taken, const int num_items, const int num_people, const int total_price, const int test_case) {
    //opens the file in append mode
    std::ofstream output_file;
    output_file.open("results.txt", std::ios::app);

    //print the results to the file
    output_file << "\n\n***Test Case " << test_case + 1 << " Result***\nTotal Price: " << total_price << "\nMember Items:";
    for(long unsigned int i = 0; i < items_taken.size(); i++) {
        output_file << "\n" << i + 1 << ": ";
        if(items_taken[i].size() > 0) { //preven seg fault if no items taken
            for(int j = (int)items_taken[i].size() - 1; j >= 0; j--) {
                output_file << items_taken[i][j] << " ";
            }
        }
    }

    output_file.close();
}



/*
 * Dynamic programming implimentation of 0-1 knapsack, adapted
 * for the shopping problem to just make the array and return
 * 
 * Running time: O(nW) -- psudo polynomial
 *
 * Params:
 *   values - vector into of values, must be of length n
 *   weights - vector into of weights, must be of length n
 *   w - maxiumum weight to make table for
 *   n - number of items to look through
 * 
 * Return:
 *   int value of maximum value with constraint of given weight w
 */
vector<vector<int>> dp_generate_array(const vector<int>& values, const vector<int>& weights, int w, int n) {
    //create array for bottom-up of size n x w
    vector<vector<int>> v(n + 1, vector<int>(w + 1));

	for(int i = 1; i <= n; i++) { //consider each item
		v[i][0] = 0; //zero first row    

		for(int j = 0; j <= w; j++){ //consider each item for each weight
            if(j == 0) {    //zero first col
                v[0][j] = 0;
            }
            if (weights[i - 1] <= j){ //can include
                v[i][j] = maximum((values[i - 1] + v[i - 1][j - weights[i - 1]]), v[i - 1][j]);
            } else {//item i is too big
                v[i][j] = v[i-1][j]; 
            }
        }
    }

    return v;

}



/*
 * Uses existing DP table to backtrace and find the optimal
 * items for each person to take
 * 
 * Running time: O()
 *
 * Params:
 *   dp_result - result from running DP algo for max_weight
*   values - vector into of values, must be of length n
 *   weights - vector into of weights, must be of length n
 *   w - capacity of person to find items for
 *   n - number of items to look through (pass all)
 * 
 * Return:
 *   vector containing int corresponding to items taken
 */
vector<int> backtrace_family(const vector<vector<int>>& dp_result, const vector<int>& values, const vector<int>& weights, int w, int num_items, int& total_price) {
    vector<int> items_taken;
    //find the max for the given persons weight
    int max_price = dp_result[num_items][w];

    //add this to the running total of the family total
    total_price += max_price;

    //backtrace and find the items they took 
    for(int i = num_items; i > 0 && max_price > 0; i--){
        if(max_price != dp_result[i-1][w]){
            //push item taken into vector
            items_taken.push_back(i); 

            //subtract its val and weight so we can keep backtracing
            max_price -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    return items_taken;
}