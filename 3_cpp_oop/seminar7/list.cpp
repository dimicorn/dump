#include <iostream>
#include <string>

// template function
template <class T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// template function specialization
void Swap(std::string& a, std::string& b) {
    std::string temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

// template struct
template <class T>
struct Node {
    T value;
    Node<T> *prev, *next;

    Node(T value, Node<T>* prev = nullptr, Node<T>* next = nullptr) : value(value), prev(prev), next(next) {};
};

// template class
template <class T>
class List {
public:
    List() : first_(nullptr), length_(0) {};

    Node<T>* GetFirst() {
        return first_;
    }

    List(const List<T>& list) : first_(nullptr), length_(list.length_) {
        Node<T>* curr = first_;
        for (Node<T>* curr_other = list.first_; curr_other != nullptr; curr_other = curr_other->next) {
            Node<T>* node = new Node<T>(curr_other->value);
            if (curr == nullptr) {
                first_ = node;
                curr = node;
                continue;
            }
            curr->next = node;
            node->prev = curr;
            curr = node;
        }
    }

    List(List<T>&& list) : first_(list.first_), length_(list.length_) {
        list.first_ = nullptr;
        list.length_ = 0;
    }

    List<T> operator=(const List<T>& other) {
        List<T> copy(other);
        std::swap(first_, copy.first_);
        std::swap(length_, copy.length_);
        return *this;
    }

    List<T> operator=(List<T>&& other) {
        std::swap(first_, other.first_);
        std::swap(length_, other.length_);
        return *this;
    }

    void Pop(Node<T>* node) {
        auto next = node->next, prev = node->prev;
        if (node == first_) {
            first_ = next;
        }
        delete node;
        if (prev != nullptr) {
            prev->next = next;
        }
        if (next != nullptr) {
            next->prev = prev;
        }
        length_ -= 1;
    }

    void PopFront() {
        Pop(first_);
    }

    void PushFront(const T& value) {
        Node<T>* node = new Node<T>(value, nullptr, first_);
        if (first_ != nullptr) {
            first_->prev = node;
        }
        first_ = node;
        length_ += 1;
    }

    int Length() const {
        return length_;
    }

    ~List() {
        auto temp = first_;
        Node<T>* next;
        while (temp != nullptr) {
            next = temp->next;
            delete temp;
            temp = next;
        }
    }

private:
    Node<T>* first_;
    int length_;
};

int main() {
    // T = int, compiler knows that from arguments
    int n = 5, m = 6;
    Swap(n, m);
    std::cout << n << ' ' << m << std::endl;

    // calls specialization
    std::string a("abc"), b("cde");
    Swap(a, b);
    std::cout << a << ' ' << b << std::endl;

    // T = int, implicit type from argument
    Node<int> node(5);
    std::cout << node.value << std::endl;

    // T = int, explicit declaration of type, test push
    List<int> list;
    std::cout << (list.Length() == 0) << ' ' << std::endl;
    list.PushFront(1);
    std::cout << (list.Length() == 1) << ' ' << (list.GetFirst()->value == 1) << ' ' << std::endl;
    list.PushFront(2);
    std::cout << (list.Length() == 2) << ' ' << (list.GetFirst()->value == 2) << ' '
    << (list.GetFirst()->next->value == 1) << std::endl;

    // copy constructor, test pop
    auto list_other = list;
    std::cout << (list_other.Length() == 2) << ' ' << (list_other.GetFirst()->value == 2)
    << ' ' << (list_other.GetFirst()->next->value == 1) << std::endl;
    list.PopFront();
    std::cout << (list.Length() == 1) << ' ' << (list.GetFirst()->value == 1) << std::endl;
    list.PopFront();
    std::cout << (list.Length() == 0) << std::endl;

    // test copy
    std::cout << (list_other.Length() == 2) << ' ' << (list_other.GetFirst()->value == 2)
    << ' ' << (list_other.GetFirst()->next->value == 1) << std::endl;

    // move operator=
    list = std::move(list_other);
    std::cout << (list_other.Length() == 0) << ' ';
    std::cout << (list.Length() == 2) << ' ' << (list.GetFirst()->value == 2) << ' '
    << (list.GetFirst()->next->value == 1) << std::endl;
    return 0;
}
