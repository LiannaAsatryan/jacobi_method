main: a
	./a

a: jacobi.o Matrix.o
	g++ main.cpp jacobi.o Matrix.o -o a

all: test clean

test: target
	./target

target: jacobi.o Matrix.o
	g++ jacobi_test.cpp jacobi.o Matrix.o -o target

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp -o Matrix.o

jacobi.o: jacobi.cpp
	g++ -c jacobi.cpp -o jacobi.o
clean: 
	rm -f a target output.txt result.txt *.o 
