INCLUDE=$(shell pwd)
TEST_SRC=$(shell find . -name '*.cpp *.hpp')
DIRS= Estruturas Eventos Excecoes

CXX=g++
CXXFLAGS= -std=c++11

EXEC=main

all:: compile 

compile::
	$(CXX) -o $(EXEC) *.cpp *.hpp Estruturas/*.hpp Eventos/*.hpp Excecoes/*.hpp $(CXXFLAGS)

test::
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(TEST_SRC)
	./$(EXEC)

clean::
	$(RM) -rf $(EXEC)