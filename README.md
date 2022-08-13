#What this project does
 This project solves the given system of linear equations using Jacobi method

#files
 in this directory there are following files
* input.txt __ it is the file where our matrix examples are arranged in the following order


	        size1
		_______
               |       |
               |matrix1|
               |_______|
 		
		size2
                _______
               |       |
               |matrix2|
               |_______|
	        ...
	       
	       
* golden.txt __ it is the file where our correct answers are located
* Matrix.h __ it is a header file which contains the declarations of the Matrix class methods.
* Matrix.cpp __  it is a cpp file which contains the implementations of the Matrix class methods.
* Makefile
* jacobi.h __ here are the declarations of the functions which solve our main problem(jacobi and other related functions)
* jacobi.cpp __ this .cpp file contains the implementations of the functions declared in jacobi.h file
* jacobi_test.cpp __ this is file where the testing is done

#description

My project solves the system of linear equations using matrixes
If the matrix is NOT STRICTLY diagonally dominant the answer is "no dominant"
If the typed size isn't a positive integer number the answer is "wrong size, cannot continue the process"
And finally, when our system has solution the answer is written like this   "sol1 sol2 sol3 ... soln"
in my golden and output files the precision is set as 4

#to run the main program type

 make 
#to clean the generated files type

 make clean 

#to run the test you type

 make test
 
to clean the generated files type

 make clean
