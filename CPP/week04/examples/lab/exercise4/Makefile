# CC = g++
# CFLAGS = -std=c++11 -Wall

# all: fibonacci

# fibonacci: fib.o main.o
# 	$(CC) $(CFLAGS) fib.o main.o -o fibonacci

# fib.o: fib.cpp fib.h
# 	$(CC) $(CFLAGS) -c fib.cpp

# main.o: main.cpp fib.h
# 	$(CC) $(CFLAGS) -c main.cpp

# clean:
# 	rm -f *.o fibonacci

CXX = g++
TARGET = fibonacci
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

CXXFLAGS = -c -Wall

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(TARGET)