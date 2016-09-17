FLAGS= -Wall -std=c++11
all:
	g++ ${FLAGS} BinaryIndexedTree.cpp IntervalTree.cpp TaskData.cpp TaskSolver.cpp XorComputer.cpp XorOfSingleValuesComputer.cpp main.cpp -o main

