//here are the declarations of the functions implemented in jacoby.cpp file
#include <string>
#include "Matrix.h"

void read(std::fstream&, Matrix&);
bool wrong_data(std::fstream&);
std::string set_precision(double, int);
bool is_real(std::string);
void jacobi(Matrix&, double*&);
void set_answer(double*, int, std::string&);
bool is_int(std::string);
