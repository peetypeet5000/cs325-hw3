CC = g++ -std=c++11 -g -Wall
all: knapsack shopping

knapsack: util.o knapsack.o
	$(CC) util.o knapsack.o -o knapsack
shopping: util.o shopping.o
	$(CC) util.o shopping.o -o shopping

util.o: util.cpp util.h
	$(CC) -c util.cpp
knapsack.o: knapsack.cpp knapsack.h
	$(CC) -c knapsack.cpp
shopping.o: shopping.cpp shopping.h
	$(CC) -c shopping.cpp


clean:
	rm *.o knapsack shopping

tar:
	tar -cvf $(exe_file).tar *.cpp *.h Makefile
