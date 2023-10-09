#include <iostream>
#include <memory>

class Any {
public:
    template <class T>
    Any(const T& value) : ptr_(std::make_unique<Holder<T>>(value)) {}


    template <class T>
    T& GetValue() {
        auto result = dynamic_cast<Holder<T>*>(ptr_.get());
        if (result) {
            return result->value;
        }
        else {
            throw std::bad_cast();
        }
    }

private:
    struct BaseHolder {
        virtual ~BaseHolder() = default;
    };

    template <class T>
    struct Holder : public BaseHolder {
        T value;

        Holder(T value) : value(value) {}
    };

    std::unique_ptr<BaseHolder> ptr_;
};



int main() {
    Any a = 42;
    // std::cout << a.GetValue<std::string>() << std::endl;
    std::cout << a.GetValue<int>() << std::endl;
    Any b = std::string("asd");
    std::cout << b.GetValue<std::string>() << std::endl;

    // TODO
    /*
    Any c(a);
    c = std::vector<int>{1, 2, 3};
    a = c;
    */
    return 0;
}
