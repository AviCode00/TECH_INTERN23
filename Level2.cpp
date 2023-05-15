/*
Name       : Avijit Mondal
Department : Masters of Computer Applications(MCA)
College    : Dr. B. C. Engineering College , Durgapur
Level      : 2
Questionn  : Write C or C++ code to implement dijkstra algorithm, kruskal algorithm and prim's algorithm in graph.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Define infinity as maximum value of unsigned long long
const unsigned long long INF = ULLONG_MAX;

// A structure to represent a weighted edge in graph
struct Edge {
    int src, dest;
    unsigned long long weight;
    Edge(int s, int d, unsigned long long w) : src(s), dest(d), weight(w) {}
};

// A structure to represent a connected, undirected and weighted graph
class Graph
{
    int V;
    vector<Edge> edges;
public:
    Graph(int v) : V(v) {}

    // Add an edge to the graph
    void addEdge(int src, int dest, unsigned long long weight)
    {
        edges.emplace_back(src, dest, weight);
        edges.emplace_back(dest, src, weight); // Add the reverse edge as well since it is an undirected graph
    }

    // Dijkstra's algorithm to find shortest path from source vertex to all other vertices
    void dijkstra(int src)
    {
        // Create a priority queue to store vertices that are being processed
        priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<pair<unsigned long long, int>>> pq;
        vector<unsigned long long> dist(V, INF);

        // Insert the source vertex with distance 0
        pq.push(make_pair(0, src));
        dist[src] = 0;

        // Loop through all vertices in priority queue
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // Loop through all adjacent vertices of u
            for (const Edge& e : edges) {
                if (e.src == u) {
                    int v = e.dest;
                    unsigned long long w = e.weight;

                    // If there is a shorter path to v through u
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }

        // Print shortest path from source vertex to all other vertices
        cout << "Dijkstra's Algorithm: Shortest path from vertex " << src << " to all other vertices:" << endl;
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INF)
                cout << i << ": INF" << endl;
            else
                cout << i << ": " << dist[i] << endl;
        }
    }

    // Kruskal's algorithm to find minimum spanning tree of the graph
    void kruskal()
    {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V);
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        vector<Edge> mst;
        for (const Edge& e : edges) {
            int u = e.src, v = e.dest;
            int pu = parent[u], pv = parent[v];

            // If including this edge does not cause cycle, include it
            if (pu != pv) {
                mst.push_back(e);
                for (int i = 0; i < V; ++i)
                    if (parent[i] == pv)
                        parent[i] = pu;
            }
        }

        // Print minimum spanning tree
        cout << "Kruskal's Algorithm: Minimum Spanning Tree of the graph:" << endl;
        for (const Edge& e : mst)
            cout << e.src << " -- " << e.dest << " (weight " << e.weight << ")" << endl;
    }
// Prim's algorithm to find minimum spanning tree of the graph
    void prim()
    {
        // Create a priority queue to store vertices that are being processed
        priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<pair<unsigned long long, int>>> pq;
        vector<bool> visited(V, false);
        vector<unsigned long long> dist(V, INF);
        vector<int> parent(V, -1);

        // Insert the first vertex with distance 0
        pq.push(make_pair(0, 0));
        dist[0] = 0;

        // Loop through all vertices in priority queue
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // If the vertex is already visited, continue
            if (visited[u])
                continue;

            visited[u] = true;

            // Loop through all adjacent vertices of u
            for (const Edge& e : edges) {
                if (e.src == u) {
                    int v = e.dest;
                    unsigned long long w = e.weight;

                    // If v is not visited and there is a shorter path to v through u
                    if (!visited[v] && w < dist[v]) {
                        dist[v] = w;
                        pq.push(make_pair(dist[v], v));
                        parent[v] = u;
                    }
                }
            }
        }

        // Print minimum spanning tree
        cout << "Prim's Algorithm: Minimum Spanning Tree of the graph:" << endl;
        for (int i = 1; i < V; ++i)
            cout << parent[i] << " -- " << i << " (weight " << dist[i] << ")" << endl;
    }
};
// Main function
    int main()
    {
// Create a graph object
        Graph g(6);
// Add edges to the graph
        g.addEdge(0, 1, 5);
        g.addEdge(0, 2, 1);
        g.addEdge(1, 2, 2);
        g.addEdge(1, 3, 6);
        g.addEdge(2, 3, 3);
        g.addEdge(2, 4, 4);
        g.addEdge(3, 4, 7);

// Run Dijkstra's algorithm from vertex 0
        g.dijkstra(0);

// Run Kruskal's algorithm to find minimum spanning tree
        g.kruskal();

// Run Prim's algorithm to find minimum spanning tree
        g.prim();

        return 0;
    }

