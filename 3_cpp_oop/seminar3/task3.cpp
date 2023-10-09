#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include "boost_1_77_0/boost/graph/depth_first_search.hpp"
#include "boost_1_77_0/boost/graph/visitors.hpp"
#include <stack>
#include <vector>
#include <utility>


using Vertex = int;

enum class Node {
    white,
    gray,
    black
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

    const std::vector<Vertex> & GetAllVertices() const{
        return all_vertices_;
    };

    const std::vector<Vertex> & GetAdjacentVertices(Vertex vertex) const {
        return edges_[vertex];
    };

private:
    int vertices_num_;
    std::vector<std::vector<Vertex>> edges_;
    std::vector<Vertex> all_vertices_;
};

class DfsVisitor{
public:
    // вот это вроде правильно
    DfsVisitor& visitor;
    DfsVisitor(DfsVisitor &visitor) : visitor(visitor) {}
    void InitializeVertex(Vertex vertex, const Graph& graph){
        invoke_visitors(visitor, vertex, graph, ::boost::on_initialize_vertex());
    }
    void StartVertex(Vertex vertex, const Graph& graph){
        invoke_visitors(visitor, vertex, graph, ::boost::on_start_vertex());
    }
    void DiscoverVertex(Vertex vertex, const Graph& graph){
        invoke_visitors(visitor, vertex, graph, ::boost::on_discover_vertex());
    }
    void ExamineEdge(const std::vector<std::vector<Vertex>>& edge, const Graph& graph){
        invoke_visitors(visitor, edge, graph, ::boost::on_examine_edge());
    }
    void TreeEdge(const std::vector<std::vector<Vertex>>& edge, const Graph& graph){
        invoke_visitors(visitor, edge, graph, ::boost::on_tree_edge());
    }
    void BackEdge(const std::vector<std::vector<Vertex>>& edge, const Graph& graph){
        invoke_visitors(visitor, edge, graph, ::boost::on_back_edge());
    }
    void ForwardOrCrossEdge(const std::vector<std::vector<Vertex>>& edge, const Graph& graph){
        invoke_visitors(visitor, edge, graph, ::boost::on_forward_or_cross_edge());
    }
    void FinishEdge(std::vector<std::vector<Vertex>>& edge, const Graph& graph){
        invoke_visitors(visitor, edge, graph, ::boost::on_finish_edge());
    }
    void FinishVertex(Vertex vertex, const Graph& graph){
        invoke_visitors(visitor, vertex, graph, ::boost::on_finish_vertex());
    }
};

// write dfs, don't change signature (name, arguments and return type)
// visitor should be called as appropriate
void DepthFirstSearch(const Graph& graph, DfsVisitor& visitor) {
    //как вызывать методы если Graph& - const??
    /*
    int vertex = 0;
    std::vector<Node> colors_;
    std::stack<Vertex> TopSort_;
    std::vector<Vertex> edges = graph.GetAdjacentVertices();
    const std::vector<Vertex>& all_vertexes = graph.GetAllVertices();
    for (int next : edges[vertex]){
        if (states[next] == Node::white) {
            states[next] = Node::gray;
            colors[next] = 1 - colors[vertex];
            is_bipartite = is_bipartite &&
                           DepthFirstSearch(next, edges, states, colors);
            states[next] = NodeState::kVisited;
        } else {
            is_bipartite = is_bipartite &&
                           (colors[next] == 1 - colors[vertex]);
        }
    }
     */
};

// implement DfsVisitor interface and GetComponentsNumber
class WeakConnectivityComponentsVisitor : public DfsVisitor {
public:
    // не понимаю как нормально объявить
    //WeakConnectivityComponentsVisitor& Wvisitor;
    int GetComponentsNumber() {
        throw std::runtime_error("Not implemented");
    }
};

// implement DfsVisitor interface and WasCycleFound
class CycleFinderVisitor : public DfsVisitor {
public:
    // не понимаю как нормально объявить
    //CycleFinderVisitor& Cvisitor;
    bool WasCycleFound(Graph& graph) {
        throw std::runtime_error("Not implemented");
    }
};



// implement DfsVisitor interface and GetTopologicalSort
class TopologicalSortVisitor : public DfsVisitor {
public:
    // не понимаю как нормально объявить
   // TopologicalSortVisitor& Tvisitor;
    std::vector<Vertex> GetTopologicalSort(Graph& graph){
        // старый код просто не работает, нужно целиком переписать
        /*
        all_vert_ = graph.GetAllVertices();
        bool top_sort = true;
        for (Vertex vert : all_vert_) {
            if (colors_[vert] == Node::white) {
                DepthFirstSearch(graph, visitor); // top_sort = DepthFirstSearch
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
         */
    }
private:
    int vert_numb_;
    std::vector<std::vector<Vertex>> edges_;
    std::vector<Vertex> all_vert_;
    std::vector<Node> colors_;
    std::stack<Vertex> TopSort_;
};

int main() {
    int vertices_num, edges_num;
    std::cin >> vertices_num >> edges_num;

    Graph graph(vertices_num);
    for (int i = 0; i < edges_num; ++i) {
        Vertex from, to;
        std::cin >> from >> to;
        graph.AddEdge(from, to);
    }
    WeakConnectivityComponentsVisitor conn_visitor;
    // Зачем мы тут вызываем ДФС если он войд и ничего не выдаст?
    DepthFirstSearch(graph, conn_visitor);
    // А потом сразу функцию наследника, которая по сути должна дублировать ДФС
    // для конкретного частного случая?
    std::cout << "number of weakly connected components is " <<
              conn_visitor.GetComponentsNumber() << std::endl;

    CycleFinderVisitor cycle_visitor;
    DepthFirstSearch(graph, cycle_visitor);
    if (cycle_visitor.WasCycleFound()) {
        std::cout << "there's at least one cycle" << std::endl;
    }
    else {
        std::cout << "there are no cycles" << std::endl;
    }

    TopologicalSortVisitor sort_visitor;
    DepthFirstSearch(graph, sort_visitor);
    auto sorted = sort_visitor.GetTopologicalSort();
    std::cout << "topological sort:" << std::endl;
    for (auto v : sorted) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    return 0;
}
