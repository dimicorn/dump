#include <iostream>
#include <climits>
#include <stdexcept>


struct Node {
    int value;
    int num;
    int ind_in_array;
};

void swap(Node* x, Node* y) {
    Node temp = *x;
    x->value = y->value;
    x->num = y->num;
    x->ind_in_array = y->ind_in_array;
    y->value = temp.value;
    y->num = temp.num;
    y->ind_in_array = temp.ind_in_array;
}

class Heap {
public:
    explicit Heap(int cap) {
        size_ = 0;
        cap_ = cap;
        harr_ = new Node[cap_];
    }

    void Heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size_ and harr_[l].value < harr_[i].value) {
            smallest = l;
        }
        if (r < size_ and harr_[r].value < harr_[smallest].value) {
            smallest = r;
        }
        if (smallest != i) {
            swap(&harr_[i], &harr_[smallest]);
            Heapify(smallest);
        }
    }

    static int parent(int i) {
        return (i - 1) / 2;
    }

    static int left(int i) {
        return (2 * i + 1);
    }

    static int right(int i) {
        return (2 * i + 2);
    }

    Node extract() {
        if (size_ == 1) {
            //
            // size_--;
            return harr_[0];
        }

        Node root = harr_[0];
        harr_[0] = harr_[size_ - 1];
        size_--;
        Heapify(0);

        return root;
    }

    void decrease(int i, int new_val) {
        harr_[i].value = new_val;
        while (i != 0 and harr_[parent(i)].value > harr_[i].value) {
            swap(&harr_[i], &harr_[parent(i)]);
            i = parent(i);
        }
    }

    void Delete(int i) {
        decrease(i, INT_MIN);
        extract();
    }

    void insert(Node k) {
        if (size_ == cap_) {
            throw std::runtime_error("Cant insert key, bruv");
        }

        size_++;
        int i = size_ - 1;

        harr_[i].value = k.value;
        harr_[i].num = k.num;
        harr_[i].ind_in_array = k.ind_in_array;

        while (i != 0 and harr_[parent(i)].value > harr_[i].value) {
            swap(&harr_[i], &harr_[parent(i)]);
            i = parent(i);
        }
    }

    ~Heap() {
        delete[] harr_;
    }

private:
    Node *harr_;
    int cap_;
    int size_;
};

int *merge(int **arr, int k, int size) {
    int *out = new int[size];
    Heap heap(k);
    for (int i = 0; i < k; ++i) {
        Node node{};
        node.num = i;
        node.ind_in_array = 1;
        node.value = arr[node.num][node.ind_in_array];

        //std::cout << "Inserting note: " << note.value << " " << note.array_num << std::endl;
        heap.insert(node);
        //std::cout << "I have successfully inserted note" << std::endl;
    }
    for (int i = 0; i < size; ++i) {
        Node last_note = heap.extract();
        std::cout << i << std::endl;
        //std::cout <<
        std::cout << last_note.value << " " << last_note.num  << " " << last_note.ind_in_array << std::endl;
        //std::cout << last_note.num_in_array << " " << arr[last_note.array_num][0] << std::endl;
        //std::cout << "arr[last_note.array_num][0]: " << arr[last_note.array_num][0] << std::endl;
        if (last_note.ind_in_array < arr[last_note.num][0]) {
            Node new_note{};
            //heap.deleteKey(last_note.value);
            last_note.ind_in_array++;
            std::cout << "last_note.num_in_array: " << last_note.ind_in_array << std::endl;
            new_note.num = last_note.num;
            new_note.ind_in_array = last_note.ind_in_array;
            new_note.value = arr[new_note.num][new_note.ind_in_array];
            heap.insert(new_note);
        } else {
            std::cout << "Reached last element in array: " << last_note.num << std::endl;
            heap.Delete(last_note.value);
        }

        out[i] = last_note.value;
        //std::cout << output[i] << std::endl;
    }

    return out;
}

int main() {
    int k, size = 0;
    std::cin >> k;
    int **arr = new int *[k];
    for (int i = 0; i < k; ++i) {
        int n;
        std::cin >> n;
        arr[i] = new int[n + 1];
        arr[i][0] = n;
        size += n;
        for (int j = 1; j < n + 1; ++j) {
            std::cin >> arr[i][j];
        }
    }
    //std::cout << "output size: " << output_size << std::endl;
    int *arr_sort = merge(arr, k, size);

    for (int i = 0; i < k; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr_sort[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr_sort;
// не хочет работать :(((
    return 0;
}
