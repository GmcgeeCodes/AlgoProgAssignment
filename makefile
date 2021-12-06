#makefile for CS4040 prog hw Gerald McGee
CXXFLAGS=-g -Wall -Werror -O2 -std=c++11 
CXX = g++

myprogram: mainprog.cc geneseq.cc
	${CXX} ${CXXFLAGS} mainprog.cc geneseq.cc -o prog1
clean: 
	-rm -f *.o
	-rm -f prog1
	rm -rf prog1.dSYM