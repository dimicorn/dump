#include <iostream>
#include <vector>
#include <stdexcept>

using Vertex = int;

class ChadGraph{

};
class Graph {
public:
    explicit Graph(int vertices_num) :
        vertices_num_(vertices_num), edges_(vertices_num), all_vertices_(vertices_num) {
            for (int i = 0; i < vertices_num; ++i) {
                all_vertices_[i] = i;
            }
        };

    void AddEdge(Vertex from, Vertex to) {
        edges_[from].push_back(to);
    };

    const std::vector<Vertex>& GetAllVertices() {
        return all_vertices_;
    };

    const std::vector<Vertex>& GetAdjacentVertices(Vertex vertex) {
        return edges_[vertex];
    };

private:
    int vertices_num_;
    std::vector<std::vector<Vertex>> edges_;
    std::vector<Vertex> all_vertices_;
};


int main(){
    cout << "Hello world!" << endl;
    return 0;
}
