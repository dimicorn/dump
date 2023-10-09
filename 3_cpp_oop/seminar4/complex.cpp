#include <iostream>

const double kComplexSquared = 3;

class Complex {
public:
    explicit Complex(double a = 0, double b = 0) : a_(a), b_(b) {};

    Complex(const Complex& c) : a_(c.a_), b_(c.b_) {};

    Complex(Complex&& c) : a_(c.a_), b_(c.b_) {};

    friend std::ostream& operator<<(std::ostream& dest, const Complex& c) {
        dest << c.a_ << " + " << c.b_ << 'i' << std::endl;
        return dest;
    }

    Complex& operator+=(const Complex& other) {
        a_ += other.a_;
        b_ += other.b_;
        return *this;
    }

    friend Complex operator+(Complex lhs, const Complex& rhs) {
        lhs += rhs;
        return lhs;
    }

    Complex& operator*=(const Complex& other) {
        double temp_a = a_;
        a_ = a_ * other.a_ + b_ * other.b_ * kComplexSquared;
        b_ = temp_a * other.b_ + other.a_ * b_;
        return *this;
    }

    friend Complex operator*(Complex lhs, const Complex& rhs) {
        lhs *= rhs;
        return lhs;
    }

    Complex& operator=(const Complex& other) {
        if (this == &other) {
            return *this;
        }

        a_ = other.a_;
        b_ = other.b_;
        return *this;
    }

    Complex& operator=(Complex&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        a_ = other.a_;
        b_ = other.b_;
        return *this;
    }

private:
    double a_, b_;
};

int main() {
    Complex a(-1, -1), b(1.5, 2), c(3);
    b += c;
    std::cout << a << b << c;
    std::cout << b + a;
    c = b * a;
    std::cout << c;
    return 0;
}
