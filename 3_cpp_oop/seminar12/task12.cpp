#include <iostream>
#include <vector>
#include <set>


int parent[1000000]; // мега костыль

int root(int vert) {
    if (vert == parent[vert]) {
        return vert;
    }
    return parent[vert] = root(parent[vert]);
}

void connect(int vert_a, int vert_b) {
    vert_a = root(vert_a);
    vert_b = root(vert_b);
    if (vert_a != vert_b) {
        parent[vert_b] = vert_a;
    }
}

void printAns(int n, std::vector<std::vector<int> > edges) {
    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }
    for (auto & edge : edges) {
        connect(edge[0], edge[1]);
    }
    std::set<int> sett;
    for (int i = 0; i < n; ++i) {
        sett.insert(root(parent[i]));
    }
    std::cout << sett.size() << std::endl;
}

int main() {
    int n = 8;
    std::vector<std::vector<int> > edges = {{1, 0}, {0, 2}, {5, 3}, {3, 4}, {6, 7}};
    printAns(n, edges);
    // оно работает :))
    return 0;
}
