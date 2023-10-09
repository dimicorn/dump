#include <iostream>
#include <memory>
#include <stdexcept>

template<class T>
class List {
private:
    struct Node;
public:
    class Iterator : public std::iterator<std::random_access_iterator_tag, T, T, T *, T&> {
    public:
        explicit Iterator(std::shared_ptr<Node> node) : node_(node) {}

        std::shared_ptr<Node> operator*() const {
            return node_;
        }
        bool operator!=(const Iterator &other) const {
            return node_ != other.node_;
        }

        Iterator &operator++() {
            if (node_) {
                node_ = node_->next;
            }
            else {
                throw std::runtime_error("Bruv, get some help");
            }
        }

        std::shared_ptr<Iterator> operator++(T) {
            std::shared_ptr<Iterator> temp = this;
            if (node_) {
                node_ = node_->next;
            }
            else {
                throw std::runtime_error("Bruv, get some help");
            }
            return temp;
        }
        friend Iterator operator+(const Iterator other, int n) {
            Iterator temp = other;
            for (int i = 0; i < n; ++i) {
                ++temp;
            }
            return temp;
        }
        std::shared_ptr<Iterator>& operator--() {
            if (node_) {
                node_ = node_->prev;
            }
            else {
                throw std::runtime_error("Bruv, get some help");
            }
        }
        std::shared_ptr<Iterator> operator--(T) {
            Iterator *temp = this;
            if (node_) {
                node_ = node_->prev;
            }
            else {
                throw std::runtime_error("Bruv, get some help");
            }
            return temp;
        }
        friend Iterator operator-(const Iterator other, int n) {
            Iterator temp = other;
            for (int i = 0; i < n; ++i) {
                --temp;
            }
            return temp;
        }
    private:
        std::shared_ptr<Node> node_;
    };

public:
    List() : first_(nullptr), length_(0) {};

    size_t Size() const {
        return length_;
    }

    bool Empty() const {
        if (length_ == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    Iterator Begin() const {
        return Iterator(first_);
    }

    Iterator End() const {
        return Iterator(nullptr);
    }

    void Insert(Iterator other, T elem) {
        Node node(elem, std::shared_ptr<Iterator>(--other), std::shared_ptr<Iterator>(++other));
        (std::shared_ptr<Iterator>(--other))->next = &node;
        (std::shared_ptr<Iterator>(++other))->prev = &node;
    }

    void PushFront(const T &other) {
        Node node(other, nullptr, first_);
        first_ = &node;
        length_++;
    }

private:
    struct Node {
        T& value;
        std::shared_ptr<Node> prev, next;

        explicit Node(const T &value, std::shared_ptr<Node> prev = nullptr, std::shared_ptr<Node> next = nullptr) :
                value(value), prev(prev), next(next) {};
    };

    std::shared_ptr<Node> first_;
    int length_;
};

int main() {
    List<int> list;

    return 0;
}

