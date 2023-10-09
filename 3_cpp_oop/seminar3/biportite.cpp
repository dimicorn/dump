#include <iostream>
#include <vector>

enum class NodeState {kNotSeen, kSeen, kVisited};

bool DepthFirstSearch(int vertex, const std::vector<std::vector<int>>& edges,
                      std::vector<NodeState>& states, std::vector<int>& colors) {
    bool is_bipartite = true;
    for (int next : edges[vertex]) {
        if (states[next] == NodeState::kNotSeen) {
            states[next] = NodeState::kSeen;
            colors[next] = 1 - colors[vertex];
            is_bipartite = is_bipartite &&
                           DepthFirstSearch(next, edges, states, colors);
            states[next] = NodeState::kVisited;
        } else {
            is_bipartite = is_bipartite &&
                           (colors[next] == 1 - colors[vertex]);
        }
    }
    return is_bipartite;
}

bool IsBipartite(int vertices_num,
                 const std::vector<std::vector<int>>& edges) {
    std::vector<NodeState> states(vertices_num, NodeState::kNotSeen);
    std::vector<int> colors(vertices_num, -1);
    states[0] = NodeState::kSeen;
    colors[0] = 0;
    return DepthFirstSearch(0, edges, states, colors);
}

int main() {
    int vertices_num, edges_num;
    std::cin >> vertices_num >> edges_num;
    std::vector<std::vector<int>> edges(vertices_num);
    for (int i = 0; i < edges_num; ++i) {
        int from, to;
        std::cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    if (IsBipartite(vertices_num, edges)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
