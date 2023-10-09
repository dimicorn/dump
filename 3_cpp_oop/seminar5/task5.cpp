#include <iostream>

class Matrix{
public:
    //конструктор
    Matrix(int n, int m, int default_value = 0): n_(n), m_(m){
        mat_ = new int*[n_];
        for (int i = 0; i < n_; ++i){
            mat_[i] = new int[m_];
        }
        for (int i = 0; i < n_; ++i){
            for (int j = 0; j < m_; ++j){
                mat_[i][j] = default_value;
            }
        }
    }

    //конструктор копирования
    Matrix(const Matrix& other): n_(other.n_), m_(other.m_){
        mat_ = new int*[other.n_];
        for (int i = 0; i < n_; ++i){
            mat_[i] = new int[other.m_];
        }
        for (int i = 0; i < n_; ++i){
            for (int j = 0; j < m_; ++j){
                mat_[i][j] = other.mat_[i][j];
            }
        }
        std::cout << "COPY";
    }

    //конструктор перемещения
    Matrix(Matrix&& other) noexcept : n_(other.n_), m_(other.m_), mat_(other.mat_){
        other.mat_ = nullptr;
        other.n_ = 0;
        other.m_ = 0;
        std::cout << "MOVE";
    }

    //оператор присваивания копирования
    Matrix& operator=(const Matrix& other){
        if (&other == this){
            return *this;
        }
        for (int i = 0; i < n_; ++i){
            delete[] mat_[i];
        }
        delete[] mat_;
        n_ = other.n_;
        m_ = other.m_;
        mat_ = new int*[n_];
        for (int i = 0; i < n_; ++i){
            mat_[i] = new int[m_];
        }
        for (int i = 0; i < n_; ++i){
            for(int j = 0; j < m_; ++j){
                mat_[i][j] = other.mat_[i][j];
            }
        }
        return *this;
    }

    //оператор присваивания перемещения
    Matrix& operator=(Matrix&& other) noexcept {
        if (&other == this){
            return *this;
        }
        for (int i = 0; i < n_; ++i){
            delete [] mat_[i];
        }
        delete[] mat_;
        n_ = other.n_;
        m_ = other.m_;
        mat_ = other.mat_;
        other.mat_ = nullptr;
        other.m_ = 0;
        other.n_ = 0;
        std::cout << "move" << std::endl;
        return *this;
    }

    //деструктор
    ~Matrix(){
        for (int i = 0; i < n_; ++i){
            delete[] mat_[i];
        }
        delete[] mat_;
    }

    //вывод
    friend std::ostream& operator<<(std::ostream& dest, const Matrix& mat){
        for (int i = 0; i < mat.n_; ++i){
            for (int j = 0; j < mat.m_; ++j){
                dest << mat.mat_[i][j] << " ";
            }
            dest << std::endl;
        }
        return dest;
    }

    int* operator[](int i) {
        return mat_[i];
    }

    Matrix& operator+=(const Matrix& other){
        if (n_ != other.n_ or m_ != other.m_){
            throw std::runtime_error("Matrices have different size, bruv");
        }
        for (int i = 0; i < n_; ++i){
            for (int j = 0; j < m_; ++j){
                mat_[i][j] += other.mat_[i][j];
            }
        }
        return *this;
    }

    friend Matrix operator+(Matrix lhs, const Matrix& rhs){
        lhs += rhs;
        return lhs;
    }

    Matrix& operator-=(const Matrix& other){
        if (n_ != other.n_ or m_ != other.m_){
            throw std::runtime_error("Matrices have different size, bruv");
        }
        for (int i = 0; i < n_; ++i){
            for (int j = 0; j < m_; ++j){
                mat_[i][j] -= other.mat_[i][j];
            }
        }
        return *this;
    }

    friend Matrix operator-(Matrix lhs, const Matrix& rhs){
        lhs -= rhs;
        return lhs;
    }

    Matrix& operator*=(const Matrix& other){
        if (m_ != other.n_){
            throw std::runtime_error("Matrices have different sizes, bruv");
        }
        int* elem = new int[n_ * other.m_];
        int q = 0;
        for (int i = 0; i < n_; ++i){
            for (int j = 0; j < other.m_; ++j){
                int a = 0;
                for (int r = 0; r < m_; ++r){
                    a += mat_[i][r] * other.mat_[r][i];
                }
                elem[q] = a;
                ++q;
            }
        }
        q = 0;
        for (int i = 0; i < n_; ++i){
            for (int j = 0; j < other.m_; ++j){
                mat_[i][j] = elem[q];
                ++q;
            }
        }
        m_ = other.m_;
        delete [] elem;
        return *this;
    }

    Matrix& operator*=(const int& k){
        for (int i = 0; i < n_; ++i){
            for (int j = 0; j < m_; ++j){
                mat_[i][j] *= k;
            }
        }
        return *this;
    }

    friend Matrix operator*(Matrix lhs, const Matrix& rhs){
        lhs *= rhs;
        return lhs;
    }

    friend Matrix operator*(Matrix lhs, const int& k){
        lhs *= k;
        return lhs;
    }

    friend Matrix operator*(const int& k, Matrix rhs){
        rhs *= k;
        return rhs;
    }

    void T(){
        Matrix res(*this);
        for (int i = 0; i < n_; ++i) {
            delete [] mat_[i];
        }
        delete [] mat_;
        std::swap(n_, m_);
        mat_ = new int* [n_];
        for (int i = 0; i < n_; ++i) {
            mat_[i] = new int [m_];
            for (int j = 0; j < m_; ++j) {
                mat_[i][j] = res.mat_[j][i];
            }
        }
    }
private:
    int m_, n_;
    int** mat_;
};

Matrix CreateMatrix() {
    return Matrix(3, 5, -1);
}
int main() {
    Matrix a(2, 3, 3);
    Matrix b(3, 2, 4);
    Matrix c(2, 3);
    //Matrix d(a);

    Matrix d = std::move(a);
    std::cout << d;
    //a *= -3;
    //std::cout << a << std::endl;
    //a.T();
    //b.T();
    //std::cout << a << std::endl;
    //std::cout << b << std::endl;
    return 0;
}
