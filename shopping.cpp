#include "shopping.h"

using std::vector;
using std::cout;

int main() {

    vector<vector<int>> data;
    read_file(data);

    int line_in_file = 1;   //skip first line

    //T Test Cases  (first int in file)
    for(int i = 0; i < data[0][0]; i++) {
        //Declare and read-in data from file
        int num_items, num_people;
        vector<int> prices, weights, people_capacity;
        read_data(num_items, num_people, line_in_file, prices, weights, people_capacity, data, i);

        //Run Algorithm


    }

}


void read_data(int& num_items, int& num_people, int& line_in_file, vector<int>& prices, vector<int>& weights, vector<int>& people_capacity, vector<vector<int>>& data, int& i) {
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
            line_in_file++;
        }

        /* Print Data for Testing */
        cout << "\n\n***Test Case: " << i + 1 << "***\nNumber of Items: " << num_items << "\nNumber of People: " << num_people;

        for(int i = 0; i < num_items; i++) {
            cout << "\nItem: " << i << " Price: " << prices[i] << " Weight: " << weights[i];
        }
        for(int i = 0; i < num_people; i++) {
            cout << "\nPerson: " << i << " Capacity: " << people_capacity[i];
        }
}


