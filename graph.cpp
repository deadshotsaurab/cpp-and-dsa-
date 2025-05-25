#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;                  // Number of vertices
    list<int>* adj;          // Pointer to an array containing adjacency lists

    // Helper function for DFS traversal
    void DFSUtil(int v, vector<bool>& visited);

public:
    // Constructor
    Graph(int V);

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // DFS traversal from a given vertex
    void DFS(int v);

    // BFS traversal from a given vertex
    void BFS(int v);
};

// Constructor to initialize graph with V vertices
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

// Add an edge to the graph (directed)
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);  // Add w to v's list
}

// Helper function for DFS that uses recursion
void Graph::DFSUtil(int v, vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it]) {
            DFSUtil(*it, visited);
        }
    }
}

// DFS traversal from a given source vertex
void Graph::DFS(int v) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

// BFS traversal from a given source vertex
void Graph::BFS(int v) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        v = q.front();
        cout << v << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex v
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
            if (!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Create a graph with V vertices
    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    // Input each edge from the user
    for (int i = 0; i < E; i++) {
        int v, w;
        cout << "Enter edge (from -> to): ";
        cin >> v >> w;
        g.addEdge(v, w); // Add edge to the graph
    }

    int start;
    cout << "Enter starting vertex for DFS and BFS: ";
    cin >> start;

    // Perform DFS and BFS traversals
    cout << "\nDFS traversal starting from vertex " << start << ":\n";
    g.DFS(start);

    cout << "\n\nBFS traversal starting from vertex " << start << ":\n";
    g.BFS(start);

    return 0;
}

