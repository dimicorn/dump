#include <iostream>
#include <string>

class Deep {
public:
    explicit Deep(int n) {
        n_ = new int;
        *n_ = n;
    };

    Deep(const Deep& other) {
        n_ = new int;
        *n_ = *other.n_;
    }

    ~Deep() {
        delete n_;
    }

    Deep& operator=(const Deep& other) {
        *n_ = *other.n_;
        return *this;
    }

    int Get() const {
        return *n_;
    }

    void Set(int n) {
        *n_ = n;
    }

private:
    int* n_;
};

class Shallow {
public:
    explicit Shallow(int n) {
        n_ = new int;
        *n_ = n;
    }

    Shallow(const Shallow& other) {
        n_ = other.n_;
    }

    ~Shallow() {
        delete n_;
    }

    Shallow& operator=(const Shallow& other) {
        n_ = other.n_;
        return *this;
    }

    int Get() const {
        return *n_;
    }

    void Set(int n) {
        *n_ = n;
    }

private:
    int* n_;
};

template <class T>
void CheckDeepness(const T& a) {
    T temp_a = a, temp_b = a;
    temp_a.Set(5);
    temp_b.Set(5);
    temp_a = temp_b;
    temp_a.Set(10);
    if (temp_b.Get() == 10) {
        std::cout << "shallow" << std::endl;
    } else if (temp_b.Get() == 5) {
        std::cout << "deep" << std::endl;
    } else {
        std::cout << "error" << std::endl;
    }
}

int main() {
    int b = 10;
    CheckDeepness(Deep(b));
    CheckDeepness(Shallow(b));

    return 0;
}
