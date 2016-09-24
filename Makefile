FLAGS= -Wall -std=c++14
all:
	g++ ${FLAGS} XorBinaryIndexedTree.cpp \
				 XorIntervalTree.cpp \
				 TaskData.cpp \
				 TaskSolver.cpp \
				 XorComputer.cpp \
				 XorOfSingleValuesComputer.cpp \
				 SuffixXorOfSingleValues.cpp \
				 main.cpp \
				 -o main

clean:
	rm main
