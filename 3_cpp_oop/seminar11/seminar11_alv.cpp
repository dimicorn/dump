#include <iostream>
#include <vector>

//insert, remove, top, creation

class Heap {
public:
    Heap() : len_(0), nums_(std::vector<std::pair<int, int>>(0)), indexes_(std::vector<int>(0)){};

    void Print() {
        for (int i = 0; i < len_; i++) {
            std::cout << nums_[i].first << " " << nums_[i].second << std::endl;
        }
    }

    void Add(int num, int vec_num){
        while (indexes_.size() <= vec_num) {
            indexes_.push_back(0);
        }
        indexes_[vec_num]++;
        len_++;
        nums_.emplace_back(std::make_pair(num, vec_num));
        int i = len_ - 1;
        while(nums_[i].first < nums_[(i-1)/2].first) {
            std::swap(nums_[i], nums_[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    std::pair<int, int> Remove() {
        std::swap(nums_[0], nums_[len_ - 1]);
        std::pair<int, int> temp = nums_[len_ - 1];
        nums_.pop_back();
        len_--;
        int i = 0;
        while (i < len_) {
            if (2*i + 2 < len_) {
                if (nums_[i].first < nums_[2*i + 1].first and nums_[i].first < nums_[2*i + 2].first) {
                    i = len_;
                }
                else {
                    if (nums_[2*i + 1].first < nums_[2*i + 2].first) {
                        std::swap(nums_[i], nums_[2 * i + 1]);
                        i = 2 * i + 1;
                    }
                    else {
                        std::swap(nums_[i], nums_[2 * i + 2]);
                        i = 2 * i + 2;
                    }
                }
            }
            else {
                if (2*i + 1 < len_) {
                        if (nums_[2*i + 1].first < nums_[i].first) {
                            std::swap(nums_[i], nums_[2 * i + 1]);
                            i = 2 * i + 1;
                        }
                        else {
                            i = len_;
                        }
                    }
                else {
                    i = len_;
                }
            }
        }
        return temp;
    }

    std::pair<int, int> Top() {
        return nums_[0];
    }

    std::vector<int>& Indexes() {
        return indexes_;
    }

private:
    int len_;
    std::vector<std::pair<int, int>> nums_;
    std::vector<int> indexes_;
};

int main() {
    int k, n, n_temp, temp;
    std::cin >> k;
    n = 0;
    std::vector<std::vector<int>> vecs(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> n_temp;
        n += n_temp;
        for (int j = 0; j < n_temp; j++) {
            std::cin >> temp;
            vecs[i].push_back(temp);
        }
    }
    Heap heap;
    for(int j = 0; j < k; j++) {
        heap.Add(vecs[j][0], j);
    }
    std::vector<int> result(0);
    //heap.Print();
    while(result.size() < n) {
        result.push_back(heap.Top().first);
        temp = heap.Remove().second;
        if (heap.Indexes()[temp] < vecs[temp].size()) {
            heap.Add(vecs[temp][heap.Indexes()[temp]], temp);
        }
    }
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}