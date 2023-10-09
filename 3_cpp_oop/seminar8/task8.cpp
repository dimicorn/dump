#include <iostream>
#include <string>

#define pass (void)0

template <class T>
class Vector{
public:
    virtual T& Get(int i) = 0;
    virtual void Set(int i, T value) = 0;
    virtual void PopBack() = 0;
    virtual void PushBack(const T& elem) = 0;
    virtual int Size() = 0;
    virtual int Capacity() = 0;
    virtual void Clear() = 0;
    virtual void Reserve(size_t n) = 0;
    virtual ~Vector()=default;

};

template <class T>
class DeepCopyVector: public Vector<T>{
public:
    explicit DeepCopyVector(int length = 0, const T& default_value = T()):
            size_(length), capacity_(2 * length){
        arr_ = new T [capacity_];
        for (int i = 0; i < size_; ++i){
            arr_[i] = default_value;
        }
    }
    DeepCopyVector(const DeepCopyVector<T>& other){
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new T [capacity_];
        for (int i = 0; i < size_; ++i){
            arr_[i] = other.arr_[i];
        }
    }
    DeepCopyVector(DeepCopyVector<T>&& other) noexcept{
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = other.arr_;
        other.size_ = 0;
        other.capacity_ = 0;
        other.arr_ = nullptr;
    }
    DeepCopyVector<T>& operator=(const DeepCopyVector<T>& other){
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
    DeepCopyVector<T>& operator=(DeepCopyVector<T>&& other) noexcept {
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
    ~DeepCopyVector() override{

        delete [] arr_;
    }
    DeepCopyVector(const std::initializer_list<T> &list): DeepCopyVector(list.size()){
        int count = 0;
        for (auto &elem:list){
            arr_[count] = elem;
            ++count;
        }
    }
    friend std::ostream& operator<<(std::ostream& dest, const DeepCopyVector<T>& v) {
        for (int i = 0; i < v.size_; ++i) {
            std::cout << v.arr_[i] << ' ';
        }
        return dest;
    }
    T& Get(int i) override{
        if (i < 0 or i >= size_) {
            throw std::runtime_error("Wrong index, bruv");
        }
        return arr_[i];
    }
    void Set(int i, T value) override{
        if (i < 0 or i >= size_) {
            throw std::runtime_error("Wrong index, bruv");
        }
        arr_[i] = value;
    }
    void PopBack() override{
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
    void PushBack(const T& elem) override{
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
    int Size() override{
        return size_;
    }
    int Capacity() override{
        return capacity_;
    }
    void Clear() override{
        size_ = 0;
        delete [] arr_;
        arr_ = new T [capacity_];
    }
    void Swap(DeepCopyVector<T>& other){
        DeepCopyVector<T> temp = *this;
        *this = other;
        other = temp;
    }
    void Reserve(size_t n) override{
        if (capacity_ >= n){
            pass;
        }
        else{
            DeepCopyVector<T> temp = *this;
            delete [] arr_;
            capacity_ = n;
            arr_ = new T [n];
            for (int i = 0; i < size_; ++i){
                arr_[i] = temp.arr_[i];
            }
        }
    }
    DeepCopyVector<T>& operator+=(const DeepCopyVector<T>& other){
        DeepCopyVector<T> temp = *this;
        capacity_ += other.capacity_;
        size_ += other.size_;
        delete [] arr_;
        arr_ = new T [capacity_];
        for (int i = 0; i < temp.size_; ++i){
            arr_[i] = temp.arr_[i];
        }
        for (int i = temp.size_; i < size_; ++i){
            arr_[i] = other.arr_[i - temp.size_];
        }
        return *this;
    }

    friend DeepCopyVector<T> operator+(DeepCopyVector<T> lhs, const DeepCopyVector<T>& rhs){
        lhs += rhs;
        return lhs;
    }

    DeepCopyVector<T>& operator*=(const int& k){
        DeepCopyVector<T> temp = *this;
        for (int i = 0; i < k - 1; ++i){
            *this += temp;
        }
        return *this;
    }
    friend DeepCopyVector<T> operator*(DeepCopyVector<T> lhs, const int& k){
        lhs *= k;
        return lhs;
    }

    friend DeepCopyVector<T> operator*(const int& k, DeepCopyVector<T> rhs){
        rhs *= k;
        return rhs;
    }
private:
    unsigned int capacity_{};
    int size_{};
    T* arr_;
};

template <class T>
class ShallowCopyVector : public Vector<T>{
public:
    explicit ShallowCopyVector(int length = 0, const T& default_value = T()):
            size_(length), capacity_(2 * length){
        deep_ = new DeepCopyVector<T>(length, default_value);
        for (int i = 0; i < size_; ++i){
            deep_->Set(i, default_value);
        }
        ++numb_;
    }
    ShallowCopyVector(const ShallowCopyVector<T>& other){
        delete deep_;
        this->deep_ = other.deep_;
        ++numb_;
    }
    ShallowCopyVector(ShallowCopyVector<T>&& other) noexcept{
        delete deep_;
        this->deep_ = other.deep_;
        //other.deep_ = nullptr;
        //++numb_;
    }
    ShallowCopyVector<T>& operator=(const ShallowCopyVector<T>& other){
        //std::cout << "copy";
        if (&other == this){
            ++numb_;
            return *this;
        }
        delete deep_;
        this->deep_ = other.deep_;
        ++numb_;
        return *this;
    }
    ShallowCopyVector<T>& operator=(ShallowCopyVector<T>&& other) noexcept {
        //std::cout << "move" << std::endl;
        if (&other == this) {
            return *this;
        }
        delete deep_;
        this->deep_ = other.deep_;
        //other.deep_ = nullptr;
        ++numb_;
        return *this;
    }
    ~ShallowCopyVector() override{
        if (numb_ == 1){
            //std::cout << "destroy" << std::endl;
            //std::cout << *deep_ << std::endl;
            delete deep_;
        }
        else{
            --numb_;
        }
    }
    ShallowCopyVector(const std::initializer_list<T> &list): ShallowCopyVector(list.size()){
        deep_ = new DeepCopyVector<T>(size_);
        int count = 0;
        for (auto &elem : list){
            deep_->Set(count, elem);
            ++count;
        }
        ++numb_;
    }
    friend std::ostream& operator<<(std::ostream& dest, const ShallowCopyVector<T>& v) {
        std::cout << *v.deep_;
        return dest;
    }
    T& Get(int i) override{
        return deep_->Get(i);
    }
    void Set(int i, T value) override{
        deep_->Set(i, value);
    }
    int Size() override{
        return deep_->Size();
    }
    int Capacity() override{
        return deep_->Capacity();
    }
    void PushBack(const T& elem) override{
        deep_->PushBack(elem);
    }
    void PopBack() override{
        deep_->PopBack();
    }
    void Reserve(size_t n) override{
        deep_->Reserve(n);
    }
    void Clear() override{
        deep_->Clear();
    }
    void Swap(ShallowCopyVector<T>& other){
        DeepCopyVector<T>* temp = other.deep_;
        other.deep_ = this->deep_;
        this->deep_ = temp;
    }

    ShallowCopyVector<T>& operator+=(ShallowCopyVector<T>& other){
        *(this->deep_) += *(other.deep_);
        return *this;
    }
    friend ShallowCopyVector<T> operator+(ShallowCopyVector<T>& lhs, ShallowCopyVector<T>& rhs){
        ShallowCopyVector<T> temp;
        *temp.deep_ = *lhs.deep_ + *rhs.deep_;
        return temp;
    }
    ShallowCopyVector<T>& operator*=(const int& k){
        *(this->deep_) *= k;
        return *this;
    }
    friend ShallowCopyVector<T> operator*(ShallowCopyVector<T> lhs, const int& k){
        ShallowCopyVector<T> temp;
        *temp.deep_ = *lhs.deep_ * k;
        return temp;
    }

    friend ShallowCopyVector<T> operator*(const int& k, ShallowCopyVector<T> rhs){
        ShallowCopyVector<T> temp;
        *temp.deep_ = k * *rhs.deep_;
        return temp;
    }
private:
    DeepCopyVector<T>* deep_;
    unsigned int capacity_{};
    int size_{};
    int numb_ = 0;
};

template <class T>
class COWVector : public Vector<T>{

};
int main() {
    ShallowCopyVector<int> v(5, 0);
    ShallowCopyVector<int> a{1, 2, 3, 4};
    ShallowCopyVector<int> c;
    c = 2 * a;
    std::cout << c;
    return 0;
}
