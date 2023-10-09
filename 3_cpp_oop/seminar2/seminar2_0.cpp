#include <iostream>
#include <vector>

class Figure {
public:
    virtual void Print() {
        std::cout << "figure" << std::endl;
    }

    virtual bool IsPointIn(int x, int y) = 0;
};

class Square : public Figure {
public:
    Square(int x1, int y1, int x2, int y2) :
        x1_(x1), y1_(y1), x2_(x2), y2_(y2) {};

    void Print() override {
        std::cout << "square" << std::endl;
    };

    bool IsPointIn(int x, int y) override {
        return x < x2_ && x > x1_ && y > y2_ && y < y1_;
    };

private:
    int x1_, y1_, x2_, y2_;
};

class Circle : public Figure {
public:
    Circle(int x, int y, int r) :
        x_(x), y_(y), r_(r) {};

    void Print() override {
        std::cout << "circle" << std::endl;
    };

    bool IsPointIn(int x, int y) override {
        return (x - x_) * (x - x_) + (y - y_) * (y - y_) < r_ * r_;
    }

private:
    int x_, y_, r_;
};

int main() {
    Square sq(-1, 1, 1, -1);
    Circle c(1, 1, 1);
    std::vector<Figure*> figs;
    figs.push_back(&sq);
    figs.push_back(&c);
    for (auto fig : figs) {
        fig -> Print();
        std::cout << fig -> IsPointIn(0, 0) << std::endl;
    }
    return 0;
}
