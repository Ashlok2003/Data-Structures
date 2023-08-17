#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii; // Pair of weight and vertex

class Graph {
public:
    int V; // Number of vertices
    vector<vector<pii>> adj; // Adjacency list

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(weight, v);
        adj[v].emplace_back(weight, u);
    }

    vector<pii> primMST(int startVertex) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        vector<int> minWeight(V, INT_MAX);

        priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap

        pq.push(make_pair(0, startVertex));
        minWeight[startVertex] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;

            for (const pii& neighbor : adj[u]) {
                int v = neighbor.second;
                int weight = neighbor.first;

                if (!visited[v] && weight < minWeight[v]) {
                    parent[v] = u;
                    minWeight[v] = weight;
                    pq.push(make_pair(minWeight[v], v));
                }
            }
        }

        vector<pii> mst;
        for (int i = 1; i < V; ++i) {
            mst.emplace_back(parent[i], i);
        }

        return mst;
    }
};

int main() {
    int V, E;
    cin >> V >> E; // Number of vertices and edges

    Graph graph(V);

    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    int startVertex;
    cin >> startVertex; // Starting vertex for MST

    vector<pii> mstEdges = graph.primMST(startVertex);

    cout << "Minimum Spanning Tree Edges:\n";
    for (const pii& edge : mstEdges) {
        cout << edge.first << " - " << edge.second << "\n";
    }

    return 0;
}
