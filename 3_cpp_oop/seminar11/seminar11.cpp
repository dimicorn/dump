#include <iostream>
#include <climits>
#include <stdexcept>

struct Note {
	int value;
	int array_num;
	int num_in_array;
};

void swap(Note *x, Note *y);

class MinHeap {
public:
    MinHeap(int capacity) {
	    heap_size_ = 0;
	    capacity_ = capacity;
	    harr_ = new Note[capacity_];
	}
  
    void MinHeapify(int i) {
	    int l = left(i);
	    int r = right(i);
	    int smallest = i;
	    if (l < heap_size_ && harr_[l].value < harr_[i].value) {
	        smallest = l;
	    }
	    if (r < heap_size_ && harr_[r].value < harr_[smallest].value) {
	        smallest = r;
	    }
	    if (smallest != i) {
	        swap(&harr_[i], &harr_[smallest]);
	        MinHeapify(smallest);
	    }
	}
  
    int parent(int i) { 
    	return (i-1)/2; 
    }
  
    int left(int i) { 
    	return (2*i + 1); 
    }

    int right(int i) { 
    	return (2*i + 2); 
    }
  
    Note extractMin() {
	    if (heap_size_ == 1) {
        	heap_size_--;
        	return harr_[0];
    	}
  
	    Note root = harr_[0];
	    harr_[0] = harr_[heap_size_-1];
	    heap_size_--;
	    MinHeapify(0);
	  
	    return root;
	}
  
    void decreaseKey(int i, int new_val) {
	    harr_[i].value = new_val;
	    while (i != 0 && harr_[parent(i)].value > harr_[i].value) {
	       swap(&harr_[i], &harr_[parent(i)]);
	       i = parent(i);
	    }
	}
  
    Note getMin() { 
    	return harr_[0]; 
    }
  
    void deleteKey(int i) {
	    decreaseKey(i, INT_MIN);
	    extractMin();
	}
  
    void insertKey(Note k) {
	    if (heap_size_ == capacity_) {
	        throw std::runtime_error("Overflow: Could not insertKey");
	    }
	  
	    heap_size_++;
	    int i = heap_size_ - 1;

	    harr_[i].value = k.value;
	  	harr_[i].array_num = k.array_num;
	    harr_[i].num_in_array = k.num_in_array;
	  
	    while (i != 0 && harr_[parent(i)].value > harr_[i].value) {
	    	swap(&harr_[i], &harr_[parent(i)]);
	    	i = parent(i);
	    }
	}

	~MinHeap() {
		delete [] harr_;	
	}
private:
	Note *harr_; 
    int capacity_; 
    int heap_size_; 
};    
  
void swap(Note *x, Note *y)
{
    Note temp = *x;
    x->value = y->value;
    x->array_num = y->array_num;
    x->num_in_array = y->num_in_array;

    y->value = temp.value;
    y->array_num = temp.array_num;
    y->num_in_array = temp.num_in_array;
}

int* mergeKArrays(int** arr, int k, int output_size) {
	int* output = new int [output_size];
	MinHeap heap(k);
	for (int i = 0; i < k; ++i) {
		Note note;
		note.array_num = i;
		note.num_in_array = 1;
		note.value = arr[note.array_num][note.num_in_array];

		heap.insertKey(note);
	}
	for (int i = 0; i < output_size; ++i) {
		Note last_note = heap.extractMin();
		std::cout << "--" << arr[last_note.array_num][0] << "--";
		if (last_note.num_in_array < arr[last_note.array_num][0]) {
			Note new_note;
			new_note.array_num = last_note.array_num;
			new_note.num_in_array = last_note.num_in_array + 1;
			new_note.value = arr[new_note.array_num][new_note.num_in_array];
			
			std::cout << "\n--- " << new_note.value << " " << new_note.array_num << " " << new_note.num_in_array << " ----\n";
			
			heap.insertKey(new_note);
			

		} else {
			std::cout << "Hello";
			heap.deleteKey(last_note.value);
		}

		output[i] = last_note.value;
	}

	return output;
}

int main() {
	int k, output_size = 0;
	std::cin >> k;
	int **arr = new int* [k];
	for (int i = 0; i < k; ++i) {
		int n;
		std::cin >> n;
		arr[i] = new int [n+1];
		arr[i][0] = n;
		output_size += n;
		for (int j = 1; j < n+1; ++j) {
			std::cin >> arr[i][j];
		}
	}

	int *arr_sort = mergeKArrays(arr, k, output_size);

	for (int i = 0; i < k; ++i) {
		delete [] arr[i];
	}
	delete [] arr;

	std::cout << std::endl;
	for (int i = 0; i < output_size; ++i) {
		std::cout << arr_sort[i] << " ";
	}
	std::cout << std::endl;
	delete [] arr_sort;

    return 0;
}
