#include <iostream>
#include <stdexcept>


template <class T>
class Vector{
public:
    explicit Vector(int length = 0, const T& default_value = 0):
    size_(length), capacity_(2 * length){
        arr_ = new T [capacity_];
        for (int i = 0; i < size_; ++i){
            arr_[i] = default_value;
        }
    }
    Vector(const Vector<T>& other){
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new T [capacity_];
        for (int i = 0; i < size_; ++i){
            arr_[i] = other.arr_[i];
        }
    }
    Vector(Vector<T>&& other) noexcept{
        other.size_ = 0;
        other.capacity_ = 0;
        other.arr_ = nullptr;
    }
    Vector<T>& operator=(const Vector<T>& other){
        if (&other == this){
            return *this;
        }
        delete [] arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new T [capacity_];
        for (int i = 0; i < size_; ++i) {
            arr_[i] = other.arr_[i];
        }
        return *this;
    }
    Vector<T>& operator=(Vector<T>&& other) noexcept {
        if (&other == this) {
            return *this;
        }
        size_ = other.size_;
        capacity_ = other.capacity_;
        delete [] arr_;
        arr_ = other.arr_;
        other.arr_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        return *this;
    }
    ~Vector() {
        delete [] arr_;
    }
    T& operator[](int i) {
        if (i < 0 or i >= size_) {
            throw std::runtime_error("Wrong index, bruv");
        }
        return arr_[i];
    }
    friend std::ostream& operator<<(std::ostream& dest, const Vector<T>& v) {
        for (int i = 0; i < v.size_; ++i) {
            std::cout << v.arr_[i] << ' ';
        }
        std::cout << std::endl << "size " << v.size_ << std::endl <<
        "capacity " << v.capacity_ << std::endl;
        return dest;
    }
    void PopBack() {
        --size_;
        if (size_ <= capacity_ / 4) {
            T *brr = new T [capacity_ / 4 + 1];
            for (int i = 0; i < size_; ++i) {
                brr[i] = arr_[i];
            }
            delete [] arr_;
            capacity_ /= 2;
            arr_ = new T [capacity_];
            for (int i = 0; i < size_; ++i) {
                arr_[i] = brr[i];
            }
            delete [] brr;
        }
    }
    void PushBack(const T& elem) {
        if (capacity_ == size_) {
            T *brr = new T [capacity_];
            for (int i = 0; i < size_; ++i) {
                brr[i] = arr_[i];
            }
            delete [] arr_;
            capacity_ *= 2;
            arr_ = new T [capacity_];
            for (int i = 0; i < size_; ++i) {
                arr_[i] = brr[i];
            }
            delete [] brr;
        }
        ++size_;
        arr_[size_-1] = elem;
    }
private:
    int capacity_{};
    int size_{};
    T* arr_;
};

int main() {
    Vector<int> v1(10, 2);
    Vector<float> v2(20, 0.01);
    Vector<int> v3;
    Vector<float> v4 = v2;
    std::cout << v1 << v2 << v3 << v4;
    Vector<Vector<int>> v5(3, v1);
    v2.PopBack();
    std::cout << v2 << std::endl;
    v2.PushBack(3.14);
    std::cout << v2 << std::endl;
    std::cout << v5 << std::endl;
    return 0;
}
