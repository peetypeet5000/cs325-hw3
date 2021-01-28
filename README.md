# CS325 - Analysis of Algorithms Homework 3
## How to run:
Language: C++
A makefile is included. Run `make` to compile the program (using g++). Run the programs with the following executable names:
* ./knapsack
* ./shopping



## Program Requirements (for reference):
### Part 1: 0-1 Knapsack: Recursive vs DP
Given weights and values of n items, select items to place in a knapsack of capacity W to maximize the total value in the knapsack. That is, given two integer arrays val[] and wt[ ] which represent values and weights associated with n items respectively and an integer W which represents knapsack capacity, determine the maximum value subset of val[] such that sum of the weights of this subset is ≤ W. Items cannot be broken or used more than once, you either select the complete item, or don’t select it. Implement both a recursive and dynamic programming algorithm to solve the 0-1 knapsack problem. Both algorithms should return the maximum total value of items that can fit in the knapsack.
* Give a verbal description and detailed pseudo-code for each algorithm.
* Implement both algorithms in one program named knapsack. Your program should randomly generate test cases that are solved using both the DP and Recursive algorithm. The program should output to the terminal: n, W, time for the DP algorithm, max for the DP, time for the Recursive algorithm, max for Recursive. The max values should be the same. Sample output is below
* Conduct experiments to collect running times for randomly generated input. Since there are two variables, n and W, you can hold one constant while varying the other and vis-a-versa. This may result in several graphs. Plot the data and fit curves.
* If the recursive algorithm is too slow you can collect data using different values of W and n. Discuss your implementation, results and how you collected the data. How does W change the running time? 
  
### Part 2: Shopping Spree
Acme Super Store is having a contest to give away shopping sprees to lucky families. If a family wins a shopping spree each person in the family can take any items in the store that he or she can carry out, however each person can only take one of each type of item. For example, one family member can take one television, one watch and one toaster, while another family member can take one television, one camera and one pair of shoes. Each item has a price (in dollars) and a weight (in pounds) and each person in the family has a limit in the total weight they can carry. Two people cannot work together to carry an item. Your job is to help the families select items for each person to carry to maximize the total price of all items the family takes. Write a dynamic programming algorithm to determine the maximum total price of items for each family and the items that each family member should select.
* Give a verbal description and give pseudo-code for your algorithm. Try to create an algorithm that is efficient in both time and storage requirements.
* What is the theoretical running time of your algorithm for one test case given N items, a family of size F, and family members who can carry at most Mi pounds for 1 ≤ i ≤ F.
* Implement your algorithm by writing a program named “shopping” (in C, C++ or Python) that compiles and runs on the OSU engineering servers. The program should satisfy the specifications below.

#### Input
The input file named “shopping.txt” consists of T test cases
* T (1 ≤ T ≤ 100) is given on the first line of the input file.
* Each test case begins with a line containing a single integer number N that indicates the number of items (1 ≤ N ≤ 100) in that test case
* Followed by N lines, each containing two integers: P and W. The first integer (1 ≤ P ≤ 5000) corresponds to the price of object and the second integer (1 ≤ W ≤ 100) corresponds to the weight of object.
* The next line contains one integer (1 ≤ F ≤ 30) which is the number of people in that family.
* The next F lines contains the maximum weight (1 ≤ M ≤ 200) that can be carried by the ith person in the family (1 ≤ i ≤ F). 

#### Output
Written to a file named “results.txt”. For each test case your program should output the maximum total price of all goods that the family can carry out during their shopping spree and for each the family member, numbered 1 ≤ i ≤ F, list the item numbers 1 ≤ N ≤ 100 that they should select.

#### Sample Input
2  
3  
72 17  
44 23  
31 24  
1  
26  
6   
3  
64 26  
85 22  
52 4  
99 18  
39 13  
54 9  
4  
23  
20  
20  
36  

#### Sample Output
Test Case 1  
Total Price 72  
Member Items  
 1: 1  
Test Case 2  
Total Price 568  
Member Items  
 1: 3 4  
 2: 3 6  
 3: 3 6  
 4: 3 4 6  




