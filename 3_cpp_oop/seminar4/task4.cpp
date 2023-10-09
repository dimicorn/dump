#include <iostream>
#include <stdexcept>


// a - числитель
// b - знаменатель
int GCD(int a, int b) {
    if (a % b == 0){
        return b;
    }
    if (b % a == 0){
        return a;
    }
    if (a > b){
        return GCD(a%b, b);
    }
    else{
        return GCD(a, b%a);
    }
}


class Fraction{
public:
    explicit Fraction(int a = 0, int b = 1): a_(a), b_(b) {
        int k = GCD(abs(a_), abs(b_));
        if (b_ < 0){
            a_ = -a_;
            b_ = -b_;
        }
        else if (b_ == 0){
            throw std::runtime_error("You're diving on zero bruv. Get some help.");
        }
        if (k != 1){
            a_ = a_ / k;
            b_ = b_ / k;
        }
    };
    friend std::ostream& operator<<(std::ostream& dest, const Fraction& c) {
        dest << c.a_ << " / " << c.b_ << std::endl;
        return dest;
    }
    Fraction& operator*=(const Fraction& other){
        a_ = a_ * other.a_;
        b_ = b_ * other.b_;
        int k = GCD(a_, b_);
        if (k != 1){
            a_ = a_ / k;
            b_ = b_ / k;
        }
        return *this;
    }
    friend Fraction operator*(Fraction lhs, const Fraction& rhs){
        lhs *= rhs;
        return lhs;
    }
    Fraction& operator/=(const Fraction& other){
        a_ = a_ * other.b_;
        b_ = b_ * other.a_;
        int k = GCD(a_, b_);
        if (k != 1){
            a_ = a_ / k;
            b_ = b_ / k;
        }
        return *this;
    }
    friend Fraction operator/(Fraction lhs, const Fraction& rhs){
        lhs /= rhs;
        return lhs;
    }
    Fraction& operator+=(const Fraction& other){
        a_ = a_ * other.b_ + other.a_ * b_;
        b_ = other.b_ * b_;
        int k = GCD(a_, b_);
        if (k != 1){
            a_ = a_ / k;
            b_ = b_ / k;
        }
        return *this;
    }
    friend Fraction operator+(Fraction lhs, const Fraction& rhs){
        lhs += rhs;
        return lhs;
    }
    Fraction& operator-=(const Fraction& other){
        a_ = a_ * other.b_ - other.a_ * b_;
        b_ = other.b_ * b_;
        int k = GCD(a_, b_);
        if (k != 1){
            a_ = a_ / k;
            b_ = b_ / k;
        }
        return *this;
    }
    friend Fraction operator-(Fraction lhs, const Fraction& rhs){
        lhs -= rhs;
        return lhs;
    }
    friend bool operator<(const Fraction& lhs, const Fraction& rhs){
        double frac1 = (lhs.a_ * 1.0) / (lhs.b_ * 1.0);
        double frac2 = (rhs.a_ * 1.0)/ (rhs.b_ * 1.0);
        return frac1 < frac2;
    }
    friend bool operator>(const Fraction& lhs, const Fraction& rhs){
        double frac1 = (lhs.a_ * 1.0) / (lhs.b_ * 1.0);
        double frac2 = (rhs.a_ * 1.0)/ (rhs.b_ * 1.0);
        return frac1 > frac2;
    }
    friend bool operator==(const Fraction& lhs, const Fraction& rhs){
        double frac1 = (lhs.a_ * 1.0) / (lhs.b_ * 1.0);
        double frac2 = (rhs.a_ * 1.0)/ (rhs.b_ * 1.0);
        return frac1 == frac2;
    }

    Fraction operator!() const{
        Fraction t(-a_, b_);
        return t;
    }
private:
    int a_, b_;
};


int main() {
    Fraction a(-1, 3);
    Fraction b (1, 2);
    Fraction c(b);
    //b = !a;
    std:: cout << "c = " << c;
    std:: cout << "b = " << b;
    return 0;
}
