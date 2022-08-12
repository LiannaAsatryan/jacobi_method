#include <cmath>
#include <fstream>
#include "jacobi.h"

const double e = 0.0001; //it is my epsilion

//this function reads the numbers from the input file,
//turns them into doubles and stores them in the matrix of double numbers
//if one of the numbers isn't a real number, the function sets mistake=true;
void read(std::fstream &i_file, Matrix &matrix)
{
        int rows = matrix.get_rows();
        int cols = rows + 1;
        std::string str;
        for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                        i_file >> str;
                        matrix(i, j) = std::stod(str);
                }
        }
}

//this function receives a file as a parameter and returns true if 
//there is an element which isn't a real number and returns false otherwise
bool wrong_data(std::fstream &file)
{
        std::string str;
        while(!file.eof()) {
                file >> str;
                if(file.eof()) {
                        break;
                }
                if(!is_real(str)) {
                        file.close();
                        return true;
                }
        }
        file.close();
        return false;
}


//this function reseives a double number <a> and an integer <n>,
//and sets the precision of <a> as <n>
std::string set_precision(double a, int n) 
{
        if(a == (-0))
                return "0";
        std::string str = std::to_string(a); //12.34 => 12.340000
        int i = 0; 
        while(str[i] != '.') {
                i++;
        }
        while((str.length()-1 > i) && str[str.length()-1] == '0') {
                str.pop_back();
        }
        if(str[str.length()-1] == '.') {
                str.pop_back();
                return str;
        }
        int after_point = str.length()-1-i;
        if(after_point > n) {
                for(int j = 0; j < after_point-n; j++) {
                        str.pop_back();
                }
        }
        return str;
}

//this function checks whether the string is a real number or not
bool is_real(std::string str) {
        int countDots = 0;
        if(str[0]=='.' || str[str.length()-1] == '.') {
                return false;
        }
        for(int i = 0; i < str.length(); i++) {
                if(str[i] == '-' && i == 0) {
                        continue;
                }
                if(str[i] < '0' || str[i] > '9') {
                        if(str[i] == '.') {
                                countDots++;
                        }
                        else{
                                return false;
                        }
                }
        }
        return countDots <= 1;
}


//this function receives a matrix, solves it with jacobi method
//and sets it's solutions in the given array of doubles <x>
//if the matrix isn't STRICTLY diagonally dominant the function sets
//x=nullptr
void jacobi(Matrix &matrix, double*& x)
{
        if(!matrix.diag_dominant()) {
                x = nullptr;
        }
        else {
                int rows = matrix.get_rows(), cols = rows+1;
                double previous[rows];
                for(int i = 0; i < rows; i++) {
		       	x[i] = 0;
		}
                bool converge = false;
                while(!converge) {
                        for(int i = 0; i < rows; i++) {
                                previous[i] = x[i];
                        }
                        for(int i=0; i<rows; i++) {
                                double sum=0;
                                for(int j = 0; j < cols - 1; j++) {
                                        sum += (matrix(i, j) * previous[j]);
                                }
                                sum -= (matrix(i, i) * previous[i]);
                                x[i] = (matrix(i, cols-1)-sum) / matrix(i, i);
                        }
                        converge = true;
                        for(int i = 0; i < rows; i++) {
                                if(std::abs(x[i]-previous[i]) > e) {
                                        converge = false;
                                        break;
                                }
                        }
                }
        }
}

//this function receives an array, the size of it and the 
//reference of a string <answer>
//if the array is nullptr, sets the <answer> = "no dominant"
//otherwise makes the array as a string and assignes it to the <answer>
void set_answer(double* x, int n, std::string &answer) {
        if(x == nullptr) {
                answer = "no dominant";
        }else{

                std::string str;
                for(int i = 0; i < n; i++) {
                        str = set_precision(x[i], 4);
                        if(i < n-1) {
                                answer += str + ' ';
                        }else {
                                answer += str;
                        }
                }
        }
}

//this function checks whether the given string is a positive integer number
bool is_int(std::string str) {
        for(int i = 0; i < str.length(); i++) {
                if(str[i] < '1' || str[i] > '9') {
                        return false;
                }
        }
        return true;
}

