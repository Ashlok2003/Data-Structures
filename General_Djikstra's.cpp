// ChatGPT Generated for Self Reference :)
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Edge representation
struct Edge {
    int to;
    int weight;
};

// Dijkstra's algorithm function
void dijkstra(vector<vector<Edge>>& graph, int source, vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF); // Initialize distances to INF
    distances[source] = 0; // Distance to source is 0

    // Priority queue to maintain the vertices with their distances from the source
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int dist_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If the current distance is greater than the distance in the distances vector,
        // then it's not a useful vertex anymore, so we skip it.
        if (dist_u > distances[u]) {
            continue;
        }

        // Relaxation step: Updating distances of neighboring vertices
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges

    vector<vector<Edge>> graph(n); // Adjacency list representation of the graph

    // Input the graph edges and their weights
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); // For undirected graphs
    }

    int source; // Source vertex for Dijkstra's algorithm
    cin >> source;

    vector<int> distances; // Vector to store the shortest distances from the source
    dijkstra(graph, source, distances);

    // Output the shortest distances from the source to all other vertices
    for (int i = 0; i < n; ++i) {
        if (distances[i] == INF) {
            cout << "Vertex " << i << " is not reachable from the source.\n";
        } else {
            cout << "Shortest distance from " << source << " to " << i << ": " << distances[i] << '\n';
        }
    }

    return 0;
}
