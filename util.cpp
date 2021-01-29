#include "util.h"


/*
 * This function returns an array of random numbers generated in a range
 *
 * Params:
 *   length - number of values you want in the array
 *   min - minimum value of the numbers in the array
 *   max - range of values in the array
 */
std::vector<int> generate_array(int length, int min, int max) {
    //allocates enough space for all
    std::vector<int> array(length);

    for(int i = 0; i < length; i++) {
        array[i] = (rand() % max) + min;
    }

    return array;

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





//opens and reads a text file line by line
void read_file(std::vector<std::vector<int>> &output) {
    //open file
    std::ifstream file;
    file.open("shopping.txt");

    //init variables
    std::string line;
    std::vector<std::string> lines;

    //tokenize file into lines
    if(file.is_open()) {
        while(getline(file, line, '\n')) {
            lines.push_back(line);
            
        }
    }

    //converts string vector into int vector
    output = parse_ints(lines);

    
    //close and return
    file.close();
    

}


/*
 * This function takes a vector of string and seperates them into a 2d vector of ints.
 *
 * Params:
 *   lines - the 1D vector of string, with int's seperated by spaces
 */
std::vector<std::vector<int>> parse_ints(std::vector<std::string> lines) {
    //preallocated output with space for all lines
    std::vector<std::vector<int>> output(lines.size());

    std::string temp = ""; //for storing numbers before adding
    int num;
    
    for(long unsigned int i = 0; i < lines.size(); i++) { //for each line
        num = 0;
        for(long unsigned int j = 0; j < (lines[i].size() + 1); j++) {  //for each char in line

            //if char is a number, add to temp
            if(lines[i][j] > 47 && lines[i][j] < 58) {
                temp += lines[i][j]; //add char to temp string

            } 
            //else, it must be a space, so insert temp number into int array
            else if(temp != "") {
                //std::cout << "\nadding " << std::stoi(temp) << " to vector";
                output[i].push_back(std::stoi(temp));
                temp.clear();
                num++;

            }

        }
    }
    
    return output;
}


void print_array(const std::vector<std::vector<int>> &output) {
    for(long unsigned int i = 0; i < output.size(); i++){
        for(long unsigned int j = 0; j < output[i].size(); j++) {
            std::cout << output[i][j] << " ";
        }

        std::cout << "\n";
        
    }
}



/*
 * This function generates n number of random numbers in range from 0 - 10000
 *
 * Params:
 *   num - the number of random numbers to be generated
 */
std::vector<int> random_numbers(int num) {
    //allocates enough space for all
    std::vector<int> random_nums(num);

    for(int i = 0; i < num; i++) {
        random_nums[i] = (rand() % 10001);
    }

    return random_nums;
}


long int get_time_mil() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec * 1000 + tp.tv_usec / 1000;


}


uint64_t get_time_micro()
{
    uint64_t micro = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return micro; 
}
