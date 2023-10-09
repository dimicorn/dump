#include <iostream>
#include <stdexcept>

template <class T>
class List {
private:
	struct Node;
public:
	class Iterator : public std::iterator <
                     std::random_access_iterator_tag,
                     T,
                     T,
                     T*,
                     T&
                     > {
    public:
        Iterator(Node *node) : node_(node) { }

        Node* operator*() const {
            return node_;
        }

        Iterator& operator++() {
            if (node_) {
            	node_ = node_->next;
            } else {
            	throw std::runtime_error("End of list reached");
            }
        }

        Iterator* operator++(T) {
            Iterator *temp = this;
            if (node_) {
            	node_ = node_->next;
            } else {
            	throw std::runtime_error("End of list reached");
            }
            return temp;
        }

        bool operator!=(const Iterator& other) const {
            return node_ != other.node_;
        }

        Iterator& operator--() {
            if (node_) {
            	node_ = node_->prev;
            } else {
            	throw std::runtime_error("End of list reached");
            }
        }

        Iterator* operator--(T) {
            Iterator *temp = this;
            if (node_) {
            	node_ = node_->prev;
            } else {
            	throw std::runtime_error("End of list reached");
            }
            return temp;
        }

        friend Iterator operator+(const Iterator it, int n) {
        	Iterator iter = it;
        	for (int i = 0; i < n; ++i) {
        		iter++;
        	}
        	return iter;
        }

        friend Iterator operator-(const Iterator it, int n) {
        	Iterator iter = it;
        	for (int i = 0; i < n; ++i) {
        		iter--;
        	}
        	return iter;
        }

    private:
        Node* node_;
    };

public:
	List() : first_(nullptr), length_(0) {};

	size_t Size() const {
		return length_;
	}

	bool Empty() const {
		if (length_ == 0) {
			return true;
		} else {
			return false;
		}
	}

	Iterator Begin() const {
		return Iterator(first_);
	}

	Iterator End() const {
		return Iterator(nullptr);
	}

	void Insert(Iterator iter, T elem) {
		Node node(elem, *(iter-1), *(iter+1));
		(*(iter-1))->next = &node;
		(*(iter+1))->prev = &node;
	}

	void Delete();

	void PushBack(const T &other);

	void PushFront(const T &other) {
		Node node(other, nullptr, first_);
		first_ = &node;
		length_++;
	}

	void PopBack();

	void PopFront();

	Iterator Find() const;
private:
	struct Node {
		T value;
		Node *prev, *next;

		Node(const T& value, Node* prev = nullptr, Node* next = nullptr) : value(value), prev(prev), next(next) {};
	};
	Node* first_;
	int length_;
};

int main() {
	List<int> list_1;

	std::cout << list_1.Size() << std::endl;
	list_1.PushFront(12);
	list_1.PushFront(10);
	list_1.PushFront(5);
	std::cout << list_1.Size() << std::endl;
	auto iter = List<int>::Iterator(list_1.Begin());
	list_1.Insert(iter+1, 120);
	std::cout << list_1.Size() << std::endl;

	return 0;
}
