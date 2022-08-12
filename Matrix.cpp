#include <iostream>
#include "Matrix.h"


Matrix::Matrix(int row)
{
	rows = row;
	//create the matrix
	int cols = rows + 1;
 	matrix = new double*[rows];
	for(int i = 0; i < rows; i++) {
		matrix[i] = new double[cols];
	}
	//fill with zeroes by default
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			matrix[i][j] = 0;
		}
	}
}
Matrix::Matrix() 
{
	rows = 0;
	matrix = nullptr;
}

Matrix::~Matrix()
{
	for(int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::print() 
{
	int cols = rows + 1;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix::swap_with_nonzero_row(int i)
{
	int cols = rows + 1;
	for (int j = i+1; j < rows; j++)
	{
        	if (matrix[j][i]=0)
        	{
                	for (int k = 0; k < cols; k++)
                	{
                		double temp = matrix[i][k];
                		matrix[i][k] = matrix[j][k];
                		matrix[j][k] = temp;
                	}
                	break;
        	}
	}
}

//this method swaps i-th row with j-th row
void Matrix::swap_rows(int i, int j) 
{
	int cols = rows + 1;
	if(i != j) {
		for (int k = 0; k < cols; k++)
		{
			double temp = matrix[i][k];
			matrix[i][k] = matrix[j][k];
			matrix[j][k] = temp;
		}
	} 
}

//this method checks if the given matrix is diagonally dominant
bool Matrix::diag_dominant() 
{
        for (int i = 0; i < rows; i++)
       	{
                double sum = 0;
                for (int j = 0; j < rows; j++) 
		{
                        sum += std::abs(matrix[i][j]);
                }
                sum -= std::abs(matrix[i][i]);
                if (std::abs(matrix[i][i]) <= sum) {
                        return false;
                }
        }
        return true;
}	
//this method returns true if there is a row in the matrix like this- (0, 0, ..., 0, t) where t is nonzero
bool Matrix::exists_wrong_row()
{
	int cols = rows + 1;
	for(int i = 0; i < rows; i++){
		bool zero = true;
		for(int j = 0; j < cols - 1; j++) {
			if(matrix[i][j] != 0) {
			        zero = false;
			        break;
			}
		}
		if(zero && matrix[i][cols-1] != 0) {
			return true;
		}
	}
	return false;
}
		
//this function returns true if there is a row in the matrix like this- (0, 0, ..., 0) 
bool Matrix::exists_zero_row()
{
	int cols = rows + 1;
	for(int i = 0; i < rows; i++){
		bool zero = true;
		for(int j = 0; j < cols; j++) {
		        if(matrix[i][j] != 0) {
		                zero = false;
		                break;
		        }
		}
		if(zero) {
		        return true;
		}
	}
	return false;
}

//this function adds the i-th row with d*(j-th row)
void Matrix::mull_add(int i, int j, double d)
{
	int cols = rows + 1;
	for (int k = 0; k < cols; k++) {
                double t = d * matrix[j][k];
                matrix[i][k] = matrix[i][k] + t;
       }
	
} 		

int Matrix::get_rows()
{
	return rows;
}



