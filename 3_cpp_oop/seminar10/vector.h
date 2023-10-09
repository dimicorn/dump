#pragma once

#include <algorithm>

class Vector {
public:
    // constructors and rule of five
    Vector() : size_(0), capacity_(1) {
        data_ = new int[capacity_];
    }

    Vector(size_t size, int default_value = 0) : size_(size), capacity_(size) {
        data_ = new int[capacity_];
        for (size_t i = 0; i < capacity_; ++i) {
            data_[i] = default_value;
        }
    }

    Vector(std::initializer_list<int> list) : size_(list.size()), capacity_(list.size()) {
        data_ = new int[capacity_];
        int i = 0;
        for (int value: list) {
            data_[i++] = value;
        }
    }

    Vector(const Vector &other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new int[capacity_];
        Copy(other.data_, data_, size_);
    }

    Vector(Vector &&other) : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    Vector &operator=(const Vector &other) {
        if (this == &other) {
            return *this;
        }

        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new int[capacity_];
        Copy(other.data_, data_, size_);
        return *this;
    }

    Vector &operator=(Vector &&other) {
        Swap(other);
        return *this;
    }

    ~Vector() {
        delete[] data_;
    }

    // capacity
    size_t Size() const {
        return size_;
    }

    size_t Capacity() const {
        return capacity_;
    }

    void Reserve(size_t capacity) {
        if (capacity > capacity_) {
            Reallocate(capacity);
        }
    }

    bool Empty() const {
        return size_ == 0;
    }

    // element access
    int operator[](size_t n) const {
        return data_[n];
    }

    int &operator[](size_t n) {
        return data_[n];
    }

    // modifiers
    void PushBack(int value) {
        if (size_ == capacity_) {
            Reallocate(2 * capacity_);
        }
        data_[size_++] = value;
    }

    void PopBack() {
        size_ -= 1;
    }

    void Swap(Vector &other) {
        std::swap(data_, other.data_);
        std::swap(capacity_, other.capacity_);
        std::swap(size_, other.size_);
    }

    void Clear() {
        size_ = 0;
    }

    class Iterator : public std::iterator<std::random_access_iterator_tag, int, int, int *, int &> {
    public:
        Iterator() = default;

        int &operator*() {
            return *ptr_;
        }

        Iterator &operator++() {
            ptr_ += 1;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ptr_ += 1;
            return temp;
        }

        bool operator!=(const Iterator &other) const {
            return ptr_ != other.ptr;
        }

        Iterator &operator--() {
            ptr_ -= 1;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            ptr_ -= 1;
            return temp;
        }

    private:
        int *ptr_;
    };

private:
    inline void Copy(int *from, int *to, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            to[i] = from[i];
        }
    }

    inline void Reallocate(size_t capacity) {
        int *temp = new int[capacity];
        Copy(data_, temp, size_);
        delete[] data_;
        data_ = temp;
        capacity_ = capacity;
    }

    size_t size_, capacity_;
    int *data_;
};
