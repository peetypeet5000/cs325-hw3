
CC = g++ -std=c++11 -g -Wall
all: mergesort mergeTime

mergesort:  merge.o util.o mergesort.o
	$(CC) merge.o util.o mergesort.o -o mergesort

mergeTime:  mergesort.o util.o mergeTime.o
	$(CC) mergesort.o util.o mergeTime.o -o mergeTime

merge.o: merge.cpp merge.h
	$(CC) -c merge.cpp
mergesort.o: mergesort.cpp mergesort.h
	$(CC) -c mergesort.cpp
util.o: util.cpp util.h
	$(CC) -c util.cpp
mergeTime.o: mergeTime.cpp mergeTime.h
	$(CC) -c mergeTime.cpp


clean:
	rm *.o mergesort mergeTime

tar:
	tar -cvf $(exe_file).tar *.cpp *.h Makefile
