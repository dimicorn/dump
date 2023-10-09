#include<iostream>
#include <stdexcept>

template<class T>
class Vector {
public:
    explicit Vector(unsigned int length, const T& default_value) : capacity_(length), size_(length) {
        arr_ = new T [capacity_];
        for (int i = 0; i < size_; ++i) {
            arr_[i] = default_value;
        }
    }
    
    Vector() {
        size_ = 0;
        capacity_ = 8;
        arr_ = new T [capacity_];
    }

    Vector(const Vector& other){
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new T [capacity_];
        for (int i = 0; i < size_; ++i) {
            arr_[i] = other.arr_[i];
        }
    }

    Vector(Vector&& other) : size_(other.size_), capacity_(other.capacity_), arr_(other.arr_) {
        other.arr_ = nullptr;
        other.n_ = 0;
    }

    Vector& operator=(const Vector& other) {
        if (&other == this) {
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

    Vector& operator=(Vector&& other) noexcept {
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
   
    T& operator[](int i) {
        if (i >= size_ || i < 0) {
            throw std::runtime_error("Invalid index received");
        }
        return arr_[i];
    }
    
    friend std::ostream& operator<<(std::ostream& dest, const Vector& vector) { 
        std::cout << std::endl;
        for (int i = 0; i < vector.size_; ++i) {
            std::cout << vector.arr_[i] << " ";
        }
        std::cout << std::endl << "size: " << vector.size_ << std::endl << "capacity: " << vector.capacity_ << std::endl;
        
        return dest;
    }

    void PushBack(const T& element) {
        if (capacity_ == size_) {
            T *buffer_arr = new T [capacity_];
            for (int i = 0; i < size_; ++i) {
                buffer_arr[i] = arr_[i];
            }
            delete [] arr_;
            capacity_ *= 2;
            arr_ = new T [capacity_];
            for (int i = 0; i < size_; ++i) {
                arr_[i] = buffer_arr[i];
            }
            delete [] buffer_arr;
        }
        size_ ++;
        arr_[size_ - 1] = element;
    }    

    void PopBack() {
        size_ --;
        if (size_ <= capacity_ / 4) {
            T *buffer_arr = new T [capacity_ / 4 + 1];
            for (int i = 0; i < size_; ++i) {
                buffer_arr[i] = arr_[i];
            }
            delete [] arr_;
            capacity_ /= 2;
            arr_ = new T [capacity_];
            for (int i = 0; i < size_; ++i) {
                arr_[i] = buffer_arr[i];
            }
            delete [] buffer_arr;
        }
    }
 
    ~Vector() {
        delete [] arr_; 
    }        

private:
    int capacity_;
    int size_;
    T *arr_;
};

int main() {
    Vector<int> v1(12, 2);
    Vector<float> v2(5, 0.1233);
    Vector<int> v3;
    Vector<float> v4 = v2;
    std::cout << v1 << v2 << v3 << v4;

    std::cout << "\nAfter push_back:\n";
    v1.PushBack(12);
    v1.PushBack(22);
    v1.PushBack(-122);
    v1.PushBack(1232);
    v1.PushBack(-12);
    v1.PushBack(-1212);
    for (int i = 0; i < 40; ++i) {
        v3.PushBack(i);
    }
    std::cout << v1 << v3;

    std::cout << "\nAfter pop_back:\n";
    for (int i = 0; i < 35; ++i) {
        v3.PopBack();
        if (i % 5 == 0) {
            std::cout << v3;
        }
    }
    for (int i = 0; i < 40; ++i) {
        v3.PushBack(i);
    }
    std::cout << v3;
    
    std::cout << "\nVector of vectors:\n";
    Vector<bool> v5(2, true);
    v5.PushBack(false);
    v5.PushBack(true);
    v5.PushBack(false);
    Vector<Vector<bool>> vv1(3, v5);
    Vector<bool> v6(3, false);
    vv1.PushBack(v6);
    vv1.PushBack(v6);
    vv1.PushBack(v5);
    std::cout << vv1 << std::endl << vv1[2][3];
    vv1.PopBack();
    vv1.PopBack();
    std::cout << vv1;
    
    return 0;
}
