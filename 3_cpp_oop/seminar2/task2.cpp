#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using Vertex = int;

enum class Node {
    white,
    gray,
    black
};

class Graph {
public:
    explicit Graph(int vert_numb) :
        vert_numb_(vert_numb), edges_(vert_numb), all_vert_(vert_numb),
            colors_(vert_numb){
            for (int i = 0; i < vert_numb; ++i) {
                all_vert_[i] = i;
                colors_[i] = Node::white;
        }
    };

    void AddEdge(Vertex from, Vertex to) {
        if (std::find(edges_[from].begin(), edges_[from].end(), to) == edges_[from].end()){
            edges_[from].push_back(to);
        }
    };

    void Read_AdjList() {
        for (int i = 0; i < vert_numb_; ++i) {
            int adj_vert_numb;
            Vertex vertex_from;
            std::cout << "Vertex_from index, vertex number: ";
            std::cin >> vertex_from >> adj_vert_numb;
            for (int j = 0; j < adj_vert_numb; ++j) {
                Vertex vertex_to;
                std::cin >> vertex_to;
                AddEdge(vertex_from, vertex_to);
            }
        }
    };

    void Read_AdjMat(){
        for (int i = 0; i < vert_numb_; ++i) {
            for (int j = 0; j < vert_numb_; ++j) {
                bool edge;
                std::cin >> edge;
                if (edge) {
                    AddEdge(i, j);
                }
            }
        }
    };

    void Read_ListOfEdges(int edges_num_) {
        for (int i = 0; i < edges_num_; ++i) {
            Vertex vertex_from, vertex_to;
            std::cin >> vertex_from >> vertex_to;
            AddEdge(vertex_from, vertex_to);
        }
    };

    Graph GetGraph(Graph graph_return) {
        return graph_return;
    }

    void TopSort() {
        bool top_sort = true;
        for (Vertex vert : all_vert_) {
            if (colors_[vert] == Node::white) {
                top_sort = DepthFirstSearch(vert, top_sort);
            }
        }
        if (top_sort) {
            std::cout << "~~~ UwU" << std::endl;
            while (!TopSort_.empty()) {
                std::cout << TopSort_.top();
                TopSort_.pop();
            }
            std::cout << std::endl;
        } else {
            std::cout << "Found a loop ~~~ UwU" << std::endl;
        }
    }

    bool DepthFirstSearch(Vertex vert, bool top_sort) {
        if (top_sort) {
            if (colors_[vert] == Node::white) {
                colors_[vert] = Node::gray;
                for (Vertex next : edges_[vert]){
                    top_sort = DepthFirstSearch(next, top_sort);
                }
                colors_[vert] = Node::black;
                TopSort_.push(vert);
            }
            if (colors_[vert] == Node::gray) {
                top_sort = false;
            }
        }
        return top_sort;
    }

private:
    int vert_numb_;
    std::vector<std::vector<Vertex>> edges_;
    std::vector<Vertex> all_vert_;
    std::vector<Node> colors_;
    std::stack<Vertex> TopSort_;
};


int main(){
    int a, n, m;
    std::cout << "Adjacency list - 0, Adjacency matrix - 1, List of edges - 2" << std::endl;
    std::cout << "Input:";
    std::cin >> a;
    if (a == 0){
        std::cout << "Number of vertices:" << std::endl;
        std::cin >> n;
        Graph graph(n);
        graph.Read_AdjList();
    }
    else if (a == 1){
        std::cout << "Number of vertices:" << std::endl;
        std::cin >> n;
        Graph graph(n);
        graph.Read_AdjMat();
    }
    else if (a == 2){
        std::cout << "Number of vertices:" << std::endl;
        std::cin >> n;
        std::cout << "Number of edges:" << std::endl;
        std::cin >> m;
        Graph graph(n);
        graph.Read_ListOfEdges(m);
        graph.TopSort();
    }
    return 0;
}
