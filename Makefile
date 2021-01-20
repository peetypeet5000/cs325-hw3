
CC = g++ -std=c++11 -g -Wall
all: mergesort3 mergesort3Time

mergesort3:  mergesort3.o util.o mergesort.o
	$(CC) mergesort3.o util.o mergesort.o -o mergesort3

mergesort3Time:  mergesort.o util.o mergesort3Time.o
	$(CC) mergesort.o util.o mergesort3Time.o -o mergesort3Time


mergesort.o: mergesort.cpp mergesort.h
	$(CC) -c mergesort.cpp
util.o: util.cpp util.h
	$(CC) -c util.cpp


clean:
	rm *.o mergesort3 mergesort3Time

tar:
	tar -cvf $(exe_file).tar *.cpp *.h Makefile
