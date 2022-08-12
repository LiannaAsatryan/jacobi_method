#include <fstream>
#include "jacobi.h"

//this function returns true if the given data 
//and the appropriate string in the given file are similiar 
bool match(std::fstream &g_file, std::string data)
{
        std::string g_str;
        getline(g_file, g_str);
        return g_str == data;
}

//this function performs the following
//operations for every matrix in the input file
// 1)reads the size of the current matrix
//  (if the given size isn't an integer number, writes the
//  appropriate message in the output file and doesn't continue the process)
// 2)creates a Matrix object with that given size, and an array <x>
//   to store the solutions
// 3)calls the <read> function which reads the current matrix
//   from the input file and stores it in the created Matrix object
// 4)calls jacobi function which stores the solutions in the <x> array
// 5)calls the <set_answer> function whichs turns our answer to a string
// 6)writes that answer in the output file
// 7)compares the answer with the corresponding line in the golden file
//   and writes the message in the result file(passed or not passed)
void testing( std::fstream &i_file,  std::fstream &o_file,  std::fstream &g_file,  std::fstream &r_file)
{
	i_file.open("input.txt", std::ios::in);
        int rows;
        bool wrong = false;
        while(!i_file.eof()) {
        	std::string answer;
		std::string str;
        	i_file >> str;
        	if(i_file.eof()) {
        		break;
        	}
        	if(!is_int(str)) {
        		answer = "wrong size, cannot continue the process";
                	wrong = true;
        	} else {
        		rows = std::stoi(str);
                	Matrix matrix(rows);
                	read(i_file, matrix);
                	double* x = new double[rows];
                	jacobi(matrix, x);
                	set_answer(x, rows, answer);
                	delete[] x;
        	}
        	o_file << answer << std::endl;
        	if(match(g_file, answer)) {
        		r_file << "-> test passed" << std::endl;
        	} else {
        		r_file << "-> test not passed" << std::endl;
        	}
        	if(wrong) {
        		break;
        	}
        }
}


//this function performs the operation of testing: 
//it opens the files, calls a function to check the file,
//if everything is ok it calls testing function
void test() 
{
        std::fstream i_file;//input
        std::fstream o_file; //output
        std::fstream r_file; //result
        std::fstream g_file; //golden
        r_file.open("result.txt", std::ios::out);
        i_file.open("input.txt", std::ios::in);
        o_file.open("output.txt", std::ios::out);
        g_file.open("golden.txt", std::ios::in);
	if(wrong_data(i_file)) {
		o_file << "something is wrong with your file" << std::endl;
	}else {
		testing(i_file, o_file, g_file, r_file);        
	}
        r_file.close();
        i_file.close();
        o_file.close();
        g_file.close();
}


int main() {
        test();
        return 0;
}

