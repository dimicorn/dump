#include <iostream>

class Array {
public:
    Array(int n, int default_value) : n_(n) {
        arr_ = new int[n_];
        for (int i = 0; i < n_; ++i) {
            arr_[i] = default_value;
        }
    }

    Array(const Array& other) : n_(other.n_) {
        arr_ = new int[other.n_];
        for (int i = 0; i < n_; ++i) {
            arr_[i] = other.arr_[i];
        }
    }

    Array(Array&& other) : n_(other.n_), arr_(other.arr_) {
        other.arr_ = nullptr;
        other.n_ = 0;
    }

    Array& operator=(const Array& other) {
        if (&other == this) {
            return *this;
        }
        delete[] arr_;
        n_ = other.n_;
        arr_ = new int[n_];
        for (int i = 0; i < n_; ++i) {
            arr_[i] = other.arr_[i];
        }
        return *this;
    }

    Array& operator=(Array&& other) noexcept {
        if (&other == this) {
            return *this;
        }
        n_ = other.n_;
        delete[] arr_;
        arr_ = other.arr_;
        other.arr_ = nullptr;
        other.n_ = 0;
        std::cout << "move" << std::endl;
        return *this;
    }

    int& operator[](int i) {
        return arr_[i];
    }

    ~Array() {
        delete[] arr_;
    }

private:
    int n_;
    int* arr_;
};

Array CreateArray() {
    return Array(5, -1);
}

int main() {
    Array arr(5, 4), brr = arr;
    arr[2] = 1;
    brr[2] = 7;
    std::cout << arr[0] << ' ' << arr[2] << std::endl;
    std::cout << brr[0] << ' ' << brr[2] << std::endl;
    arr = brr;
    std::cout << arr[0] << ' ' << arr[2] << std::endl;
    brr = CreateArray();
    std::cout << brr[0] << ' ' << brr[2] << std::endl;
    arr = std::move(brr);
    std::cout << arr[0] << ' ' << arr[2] << std::endl;
    return 0;
}
