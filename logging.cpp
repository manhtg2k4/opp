#include <iostream>

// Lop ma tran
class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        // Khoi tao ma tran
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        // H?y b? ma tr?n
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // N?p ch?ng toán t? c?ng ma tr?n
    Matrix operator+(const Matrix& other) const {
        // Ghi log
        log("Performing matrix addition");

        // Th?c hi?n phép toán c?ng
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // N?p ch?ng toán t? tr? ma tr?n
    Matrix operator-(const Matrix& other) const {
        // Ghi log
        log("Performing matrix subtraction");

        // Th?c hi?n phép toán tr?
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // N?p ch?ng toán t? nhân ma tr?n
    Matrix operator*(const Matrix& other) const {
        // Ghi log
        log("Performing matrix multiplication");

        // Th?c hi?n phép toán nhân
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Nap chong toan tu chia ma tran
    Matrix operator/(const Matrix& other) const {
        // Ghi log
        log("Performing matrix division");

        // Thuc hien phep toan chia 
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] / other.data[i][j];
            }
        }
        return result;
    }

    // Phuong thuc ghi log
    void log(const std::string& message) const {
        std::cout << "[LOG] " << message << std::endl;
    }

    // Phuong thuc de nhap gia tri cho ma tran
    void inputMatrix() {
        std::cout << "Enter matrix values:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Matrix[" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    // Phuong thuc in ma tran
    void print() const {
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Nhap gia tri cho hai ma tran
    Matrix matrix1(2, 2);
    matrix1.inputMatrix();

    Matrix matrix2(2, 2);
    matrix2.inputMatrix();

    // Thuc hien cac phep toan va in ket qua
    (matrix1 + matrix2).print();
    (matrix1 - matrix2).print();
    (matrix1 * matrix2).print();
    (matrix1 / matrix2).print();

    return 0;
}
