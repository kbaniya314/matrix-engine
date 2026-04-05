#include <iostream>

class Matrix {
public:
	int rows;
	int cols;
	int** data;

	Matrix (int r, int c) {
		rows = r;
		cols = c;
		data = new int *[rows];
		for (int i = 0; i < rows; i++){
			data[i] = new int [cols];
		}
	}

	void print() {
		for (int i=0; i<rows;i++){
			for (int j = 0; j<cols; j++){
				std::cout << "|" << data[i][j] << "|";
			}
		std::cout << std::endl;
		}
	}

	~Matrix() {
		for (int i = 0; i < rows; i++) {
        	delete[] data[i];
    	}
    	delete[] data;
	}
};

int main () {
	Matrix m(3,3);
	int val = 1;
	for (int i = 0; i<m.rows; i++)
		for (int j=0; j<m.cols; j++)
				m.data[i][j] = val++;
	m.print();
	return 0;
}
