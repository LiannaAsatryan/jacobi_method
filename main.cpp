#include "jacobi.h"
#include <fstream>

int main()
{
        std::fstream i_file;
        std::fstream o_file;
        i_file.open("input.txt", std::ios::in);
        o_file.open("output.txt", std::ios::out);
        if(wrong_data(i_file)) {
                o_file << "something is wrong with your file" << std::endl;
        }else {
                i_file.open("input.txt", std::ios::in);
                int rows;
                bool wrong = false;
                while(!i_file.eof()) {
                        std::string answer, str;
                        i_file >> str;
                        if(i_file.eof()) {
                                break;
                        }
                        if(!is_int(str)) {
                                answer = "wrong size, cannot continue the process";
                                wrong=true;
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
                        if(wrong) {
                                break;
                        }
                }
        }
        i_file.close();
        o_file.close();
}


