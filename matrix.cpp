#include<iostream>

class Matrix{
	public:
	int rows;
	int cols;
	int* data;

	Matrix (int r, int c){
		rows = r;
		cols = c;
		data = new int[rows*cols];
	}

	void print(){
		for (int i=0;i<rows;i++){
			for (int j=0;j<cols;j++){
				std::cout << "|" << data[i*cols+j] << "|";
			}
		std::cout << std::endl;
		}
	}

	void input(){
		for (int i=0;i<rows;i++){
                        for (int j=0;j<cols;j++){
                                std::cout << "Enter the element [" << i << ", " << j << "] : ";
				std::cin >> data[i*cols+j];
			}
		}
	}

	Matrix multiply(Matrix& other) {
		Matrix result(rows, other.cols);
		for (int i = 0; i < rows; i++) {
        		for (int j = 0; j < other.cols; j++) {
            			result.data[i * other.cols + j] = 0;
            			for (int k = 0; k < cols; k++) {
                			result.data[i * other.cols + j] += 
                    			data[i * cols + k] * other.data[k * other.cols + j];
            			}
        		}
    		}
    		return result;
	}


	~Matrix() {
    		delete[] data;
	}
};

int main (){
	int r1,c1,r2,c2;
	std::cout << " Welcome to Matrix World" << std::endl;
	std::cout << " ______________________ " << std::endl;
	std::cout << std::endl << "We are multiplying two matrices" << std::endl;
	std::cout << "The first matrix" << std::endl;
	std::cout << "++++++++++++++++" << std::endl;
	std::cout << "Enter the number of rows for this matrix: ";
	std::cin >> r1;
	std::cout << "Enter the number of columns for this matrix: ";
	std::cin >> c1;

	std::cout << " ______________________ " << std::endl;
	std::cout << "The second matrix" << std::endl;
        std::cout << "++++++++++++++++" << std::endl;
        std::cout << "Enter the number of rows for this matrix: ";
        std::cin >> r2;
        std::cout << "Enter the number of columns for this matrix: ";
        std::cin >> c2;

	if (c1==r2){
		std::cout << "Nice. Now, let's multiply them." << std::endl;
	}
	else{
		std::cout << "Sorry. Try again. The number of columns of first matrix should be equal to the number of rows of the second. ";
		std::cout << std::endl;
	return 0;
	}

	Matrix m1(r1,c1);
	Matrix m2(r2,c2);
	std::cout << "Okay! Enter your first matrix: " << std::endl;
	m1.input();
	std::cout << "Great! Now the second matrix: " << std::endl;
	m2.input();

	std::cout << "Matrix 1 is: " << std::endl;
	m1.print();

	std::cout << " ______________________ " << std::endl;

	std::cout << "Matrix 2 is: " << std::endl;
        m2.print();

	Matrix result = m1.multiply(m2);
	std::cout << "Result:" << std::endl;
	result.print();
	return 0;
}
