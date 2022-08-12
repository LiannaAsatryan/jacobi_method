#include <iostream>
//this is my Matrix class
//in this class objects cols=rows+1, where <cols> is the number of columns and <rows> is the number of rows

class Matrix{
	private:
		int rows;
		double** matrix;
	public:
		inline double& operator()(int x, int y) {
			return matrix[x][y];
		}
	 	Matrix(int);
	 	Matrix();
		~Matrix();
		void print();
		void swap_with_nonzero_row(int);
		void swap_rows(int, int); 
		bool diag_dominant();
		bool exists_wrong_row();
		bool exists_zero_row();
		void mull_add(int, int, double);	
		int get_rows();
};


























