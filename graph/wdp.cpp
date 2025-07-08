#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    unordered_map<int, int> edges; // dest → weight
};

class Weighted_Directed_Graph {
private:
    vector<Node> nodes;

public:
    // Add a new node with a value
    int addNode(int value) {
        nodes.push_back({value, {}});
        return nodes.size() - 1;
    }

    // Add or update edge
    void addEdge(int src, int dest, int weight) {
        if (src < 0 || dest < 0 || src >= nodes.size() || dest >= nodes.size()) {
            cout << "Invalid node ID\n";
            return;
        }
        nodes[src].edges[dest] = weight;
    }

    // Get value of a node
    int getNodeValue(int nodeId) {
        if (nodeId < 0 || nodeId >= nodes.size()) {
            cout << "Invalid node ID\n";
            return -1;
        }
        return nodes[nodeId].value;
    }

    // Optional: Print the graph
    void print() const {
        for (int i = 0; i < nodes.size(); ++i) {
            cout << "Node " << i << " (value = " << nodes[i].value << ") -> ";
            for (const auto& [dest, weight] : nodes[i].edges) {
                cout << "(" << dest << ", weight = " << weight << ") ";
            }
            cout << '\n';
        }
    }

    void getEdgeInfo(int u, int v) {
        if (u < 0 || v < 0 || u >= nodes.size() || v >= nodes.size()) {
            cout << "Invalid node IDs\n";
            return;
        }

        bool found = false;

        if (nodes[u].edges.count(v)) {
            cout << "Edge from " << u << " → " << v
                << " with weight " << nodes[u].edges[v] << '\n';
            found = true;
        }

        if (nodes[v].edges.count(u)) {
            cout << "Edge from " << v << " → " << u
                << " with weight " << nodes[v].edges[u] << '\n';
            found = true;
        }

        if (!found) {
            cout << "No edge exists between " << u << " and " << v << '\n';
        }
    }

    void showConnections() const {
        for (int i = 0; i < nodes.size(); ++i) {
            cout << i << " -->> ";
            for (const auto& [neighbor, weight] : nodes[i].edges) {
                cout << neighbor << "(" << weight << ") ";
            }
            cout << '\n';
        }
    }
    // Get the number of nodes in the graph
    int getNumNodes() const {
        return nodes.size();
    }

    bool dfsHasCycle(int node, vector<bool>& visited, vector<bool>& recStack) const {
        visited[node] = true;
        recStack[node] = true;

        for (const auto& [neighbor, _] : nodes[node].edges) {
            if (!visited[neighbor]) {
                if (dfsHasCycle(neighbor, visited, recStack))
                    return true;
            } else if (recStack[neighbor]) {
                return true; // found a back edge
            }
        }

        recStack[node] = false;
        return false;
    }

    bool hasCycle() const {
        int n = nodes.size();
        vector<bool> visited(n, false);
        vector<bool> recStack(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dfsHasCycle(i, visited, recStack))
                return true;
        }
        return false;
    }

};

int main() {
    Weighted_Directed_Graph g;

    int a = g.addNode(10); // 0
    int b = g.addNode(20); // 1
    int c = g.addNode(30); // 2

    g.addEdge(a, b, 5);
    g.addEdge(b, c, 7);
    g.addEdge(c, a, 3); // creates cycle

    g.showConnections();

    cout << "\nChecking for cycle...\n";
    if (g.hasCycle())
        cout << "Cycle detected \n";
    else
        cout << "No cycle \n";

    // Remove the cycle
    Weighted_Directed_Graph g2;
    int x = g2.addNode(1); // 0
    int y = g2.addNode(2); // 1
    int z = g2.addNode(3); // 2

    g2.addEdge(x, y, 1);
    g2.addEdge(y, z, 1);
    // no edge from z → x

    cout << "\nGraph without cycle:\n";
    g2.showConnections();
    cout << "Checking for cycle...\n";
    if (g2.hasCycle())
        cout << "Cycle detected \n";
    else
        cout << "No cycle \n";
    /*
    0 -->> 1(5) 
    1 -->> 2(7)
    2 -->> 0(3)

    Checking for cycle...
    Cycle detected

    Graph without cycle:
    0 -->> 1(1)
    1 -->> 2(1)
    2 -->>
    Checking for cycle...
    No cycle
    */
}

