#include "knapsack.h"

using std::vector;
using std::cout;


/*
 * Driver function to test runtimes of two Knapsack Algorithms
 *
 */
int main() {

    srand(time(NULL));

    /* Variable Items */
    cout << "***Varying Items Test***\n";
    for(int n = 6; n < 31; n = n + 3) {
        int w = 100;
        vector<int> weights = generate_array(n, 1, 20); //values 1-25
        vector<int> values = generate_array(n, 1, 100); //values 1-25
        
        /* DP TEST */
        long int start_time_dp = get_time_mil();
        int max_val_dp = dp_knapsack(values, weights, w, n);
        long int end_time_dp = get_time_mil();

        /* RECURSIVE TEST */
        long int start_time_recurs = get_time_mil();
        int max_val_recurs = recursive_knapsack(values, weights, w, n);
        long int end_time_recurs = get_time_mil();


        /* PRINT RESULTS */
        cout << "n = " << n << " w = " << w << " Rec time = " << end_time_recurs - start_time_recurs << " DP time = " << end_time_dp - start_time_dp << " Max rec = " << max_val_recurs << " Max DP = " << max_val_dp << '\n'; 
    }

    /* Variable Weights */
    cout << "\n***Varying Weights Test***\n";
    for(int w = 20000; w < 200001; w = w + 20000) {
        int n = 20;
        vector<int> weights = generate_array(n, 1, 1000); //values 1-25
        vector<int> values = generate_array(n, 1, 100); //values 1-25
        
        /* DP TEST */
        long int start_time_dp = get_time_mil();
        int max_val_dp = dp_knapsack(values, weights, w, n);
        long int end_time_dp = get_time_mil();

        /* RECURSIVE TEST */
        long int start_time_recurs = get_time_mil();
        int max_val_recurs = recursive_knapsack(values, weights, w, n);
        long int end_time_recurs = get_time_mil();


        /* PRINT RESULTS */
        cout << "n = " << n << " w = " << w << " Rec time = " << end_time_recurs - start_time_recurs << " DP time = " << end_time_dp - start_time_dp << " Max rec = " << max_val_recurs << " Max DP = " << max_val_dp << '\n'; 
    }

    

}



/*
 * This is a recursive implimentation of the knapsack algorithm.
 * 
 * Running time: O(n2^n)
 *
 * Params:
 *   values - vector into of values, must be of length n
 *   weights - vector into of weights, must be of length n
 *   w - maxiumum weight of the knapsack
 *   n - number of items to look through
 * 
 * Return:
 *   int value of maximum value of knapsack of given weight w
 */
int recursive_knapsack(vector<int> values, vector<int> weights, int w, int n) {
    //BASE CASE: no obj or no space left
    if(n == 0 || w == 0) {
        return 0; 
    }

    //CASE: Item too heavy
    if(weights[n - 1] > w) {
        return recursive_knapsack(values, weights, w, n-1);
    }

    //CASE: Test if including object will increse max value
    return maximum((values[n - 1] + recursive_knapsack(values, weights, w - weights[n - 1], n-1)), recursive_knapsack(values, weights, w, n-1));
}



/*
 * Helper function to return max of two ints
 *
 * Params:
 *   a - first int to compare
 *   b - second
 * 
 * Return:
 *   larger of a or b (or b if equal)
 */
int maximum(int a, int b) {
    if(a > b) {
        return a;
    }

    return b;
}



/*
 * This is a dynamic programming implimentation of the knapsack algorithm.
 * 
 * Running time: O(nW) -- psudo polynomial
 *
 * Params:
 *   values - vector into of values, must be of length n
 *   weights - vector into of weights, must be of length n
 *   w - maxiumum weight of the knapsack
 *   n - number of items to look through
 * 
 * Return:
 *   int value of maximum value of knapsack of given weight w
 */
int dp_knapsack(vector<int> values, vector<int> weights, int w, int n) {
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

    return v[n][w];

}