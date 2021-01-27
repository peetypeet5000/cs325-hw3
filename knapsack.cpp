#include "knapsack.h"

using std::vector;
using std::cout;

int main() {

    vector<int> weights = generate_array(100, 1, 25);

    for(int n = 3; n < 25; n++) {
        vector<int> weights = generate_array(n, 1, 25); //values 1-25
        vector<int> values = generate_array(n, 1, 25); //values 1-25
        long int start_time = get_time_mil();
        int w = 50;

        int max_val = recursive_knapsack(values, weights, w, n);

        long int end_time = get_time_mil();

        cout << "n = " << n << " w = " << w << " Rec time = " << start_time - end_time << " Max rec = " << max_val << '\n'; 
    }

}



int recursive_knapsack(vector<int> values, vector<int> weights, int w, int n) {
    //BASE CASE: no obj or no space left
    if(n == 0 || w == 0) {
        return 0; 
    }

    //CASE: Item too heavy
    if(weights[n] > w) {
        recursive_knapsack(values, weights, w, n-1);
    }

    //CASE: Test if including object will increse max value
    else {
        return maximum((values[n] + recursive_knapsack(values, weights, w - weights[n], n-1)), recursive_knapsack(values, weights, w, n-1));
    }
}


int maximum(int a, int b) {
    if(a > b) {
        return a;
    }

    return b;
}