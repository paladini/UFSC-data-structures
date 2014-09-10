INCLUDE=$(shell pwd)
TEST_SRC=$(shell find . -name '*.cpp')

CXXFLAGS=-Wall -std=c++11 -I$(INCLUDE) -lgtest

EXEC=test

all:: test

test::
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(TEST_SRC)
	./$(EXEC)

clean::
	$(RM) -rf $(EXEC)
