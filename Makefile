CC = g++ -std=c++11 -g -Wall
all: knapsack

knapsack: util.o knapsack.o
	$(CC) util.o knapsack.o -o knapsack

util.o: util.cpp util.h
	$(CC) -c util.cpp
knapsack.o: knapsack.cpp knapsack.h
	$(CC) -c knapsack.cpp


clean:
	rm *.o knapsack

tar:
	tar -cvf $(exe_file).tar *.cpp *.h Makefile
