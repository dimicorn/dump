#include<iostream>
#include<stdexcept>

class Matrix {
public:
    Matrix(int a, int b, int default_value = 0) : columns_num_(a), lines_num_(b) {
        matrix_ = new int *[lines_num_];
        for (int i = 0; i < lines_num_; ++i) {
            matrix_[i] = new int [columns_num_];
            for (int j = 0; j < columns_num_; ++j) {
                matrix_[i][j] = default_value;
            }
        }
    }
    
    Matrix(const Matrix& other) : columns_num_(other.columns_num_), lines_num_(other.lines_num_) {
        matrix_ = new int *[other.lines_num_];
        for (int i = 0; i < other.lines_num_; ++i) {
            matrix_[i] = new int [other.columns_num_];
            for (int j = 0; j < other.columns_num_; ++j) {
                matrix_[i][j] = other.matrix_[i][j];
            }
        } 
    }

    Matrix(Matrix&& other) : columns_num_(other.columns_num_), lines_num_(other.lines_num_), matrix_(other.matrix_) {
        other.matrix_ = nullptr;
        other.lines_num_ = 0;
        other.columns_num_ = 0;
    }
    
    Matrix& operator=(const Matrix& other) {
        if (&other == this) {
            return *this;
        }
        for (int i = 0; i < lines_num_; ++i) {
            delete [] matrix_[i];
        }
        delete [] matrix_;
        columns_num_ = other.columns_num_;
        lines_num_ = other.lines_num_;
        matrix_ = other.matrix_;
        return *this;
    }
    
    Matrix& operator=(Matrix&& other) noexcept {
        if (&other == this) {
            return *this;
        }
        for (int i = 0; i < lines_num_; ++i) {
            delete [] matrix_[i];
        }
        delete [] matrix_;
        columns_num_ = other.columns_num_;
        lines_num_ = other.lines_num_;
        matrix_ = other.matrix_;
        other.matrix_ = nullptr;
        other.columns_num_ = 0;
        other.lines_num_ = 0;
        return *this;
    }

    int& operator()(int line, int column) {
        if (column >= columns_num_ || line >= lines_num_) {
            throw std::runtime_error("Matrix subscript out of bounds");
        }
        return matrix_[line][column];      
    }

    Matrix& operator+=(const Matrix& other) {
        if (columns_num_ != other.columns_num_ || lines_num_ != other.lines_num_) {
            throw std::runtime_error("Matrix sizes do not match");
        }
        for (int i = 0; i < lines_num_; ++i) {
            for (int j = 0; j < columns_num_; ++j) {
                matrix_[i][j] += other.matrix_[i][j];
            }
        }
        return *this;
    }

    friend Matrix operator+(Matrix matrix_1, const Matrix& matrix_2) {
        matrix_1 += matrix_2;
        return matrix_1;
    }

    Matrix& operator-=(const Matrix& other) {
        Matrix matrix = -1 * other;
        *this += matrix;
        return *this;
    }

    friend Matrix operator-(Matrix matrix_1, const Matrix& matrix_2) {
        matrix_1 -= matrix_2;
        return matrix_1;
    }

    Matrix& operator*=(const Matrix& other) {
        if (columns_num_ != other.lines_num_) {
            throw std::runtime_error("Matrix sizes do not match");
        }
        Matrix buff_matrix(*this);
        for (int i = 0; i < lines_num_; ++i) {
            delete [] matrix_[i];
        }
        delete [] matrix_;
        columns_num_ = other.columns_num_;
        matrix_ = new int* [lines_num_];
        for (int i = 0; i < lines_num_; ++i) {
            matrix_[i] = new int [columns_num_];
            for (int j = 0; j < columns_num_; ++j) {
                matrix_[i][j] = 0;
                for (int k = 0; k < other.lines_num_; ++k) {
                    matrix_[i][j] += buff_matrix.matrix_[i][k] * other.matrix_[k][j];
                }      
            }
        }

        return *this;
    }
    
    Matrix& operator*=(const int& number) {
        for (int i = 0; i < lines_num_; ++i) {
            for (int j = 0; j < columns_num_; ++j) {
                matrix_[i][j] *= number;
            }
        }
        return *this;
    }

    friend Matrix operator*(Matrix matrix_1, const Matrix& matrix_2) {
        matrix_1 *= matrix_2;
        return matrix_1;
    }
    
    friend Matrix operator*(Matrix matrix, const int& number) {
        matrix *= number;
        return matrix;
    }

    friend Matrix operator*(const int& number, Matrix matrix) {
        matrix *= number;
        return matrix;
    }
    
    void T() {
        Matrix buff_matrix(*this);
        for (int i = 0; i < lines_num_; ++i) {
            delete [] matrix_[i];
        }
        delete [] matrix_;
        std::swap(lines_num_, columns_num_);
        matrix_ = new int* [lines_num_];
        for (int i = 0; i < lines_num_; ++i) {
            matrix_[i] = new int [columns_num_];
            for (int j = 0; j < columns_num_; ++j) {
                matrix_[i][j] = buff_matrix.matrix_[j][i];
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& dest, const Matrix& matrix) { 
        std::cout << "\n===================================\n";
        for (int i = 0; i < matrix.lines_num_; ++i) {
            for (int j = 0; j < matrix.columns_num_; ++j) {
                std::cout << matrix.matrix_[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "===================================\n";
        
        return dest;
     }    

    ~Matrix() {
        for (int i = 0; i < lines_num_; ++i) {
            delete [] matrix_[i];
        }
        delete [] matrix_;
    }
private:
    int columns_num_;
    int lines_num_;
    int **matrix_;
};

int main() {
    int a, b;
    double default_value;
    std::cout << "Enter two numbers - matrix size:\n";
    std::cin >> a >> b;
    std::cout << "Enter the default value in the matrix:\n";
    std::cin >> default_value;
    
    Matrix matrix_1(a, b, default_value), matrix_2(a, b);   
    
    std::cout << matrix_1; 
    matrix_2(0, 0) = 12;
    matrix_2(1, 1) = 32;
    std::cout << matrix_2;    
    
    Matrix matrix_3(a+1, b, 2);
    std::cout << matrix_3;
    matrix_1.T();
    matrix_3 = matrix_2 * matrix_1;
    std::cout << matrix_3;
    
    return 0;
}
