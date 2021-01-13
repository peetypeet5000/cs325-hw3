#include "util.h"


std::vector<std::vector<int>> read_file(std::vector<std::vector<int>> &output) {
    //open file
    std::ifstream file;
    file.open("data.txt");

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
    
    /* for checking
    read_array(output);
    */
    

    
    //close and return
    file.close();
    return output;
    

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
                if(num != 0) {  //ignores first value, as it is not actually in the data
                    //std::cout << "\nadding " << std::stoi(temp) << " to vector";
                    output[i].push_back(std::stoi(temp));
                }
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
