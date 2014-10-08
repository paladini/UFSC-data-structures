INCLUDE=$(shell pwd)
TEST_SRC=$(shell find . -name '*.cpp *.hpp')

CXX=g++
CXXFLAGS=-Wall -std=c++11 -I$(INCLUDE)

EXEC=test

all:: test

test::
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(TEST_SRC)
	./$(EXEC)

clean::
	$(RM) -rf $(EXEC)