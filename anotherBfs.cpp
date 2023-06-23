// Online C++ compiler to run C++ program online
#include <iostream>

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> bfs_shortest_path(vector<vector<int>>& graph, int source, int destination) {
    queue<int> q;
    q.push(source);

    vector<bool> visited(graph.size(), false);
    visited[source] = true;

    vector<int> parent(graph.size(), -1);

    while (!q.empty()) {
        int current_vertex = q.front();
        q.pop();

        if (current_vertex == destination)
            break;

        for (auto& neighborInfo : graph[current_vertex]) {
            int neighbor = neighborInfo;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = current_vertex;
            }
        }
    }

    if (parent[destination] == -1)
        return {};  // No path exists

    // Reconstruct the path
    vector<int> path;
    int current_vertex = destination;
    while (current_vertex != -1) {
        path.push_back(current_vertex);
        current_vertex = parent[current_vertex];
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int num_vertices, num_edges;
    cout << "Enter the number of vertices: ";
    cin >> num_vertices;
    cout << "Enter the number of edges: ";
    cin >> num_edges;
    int lastPseudoVertex = num_edges;
    vector<vector<pair<int, int> > > weightedGraph(num_vertices);
    vector<vector< int> > graph(2*num_vertices);
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < num_edges; ++i) {
        int u, v;
        int weight;
        cin >> u >> v;
        cin >> weight;
        if( weight == 2) {
            graph[ u].push_back(lastPseudoVertex);
            graph[ lastPseudoVertex].push_back(v);
            graph[ v].push_back(lastPseudoVertex);
            graph[ lastPseudoVertex].push_back(u);
            lastPseudoVertex++;
        } else {
            graph[ u].push_back(v);
            graph[v].push_back(u);
        }
    }
    

    
    int source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    vector<int> shortest_path = bfs_shortest_path(graph, source, destination);

    if (shortest_path.empty()) {
        cout << "No path exists between the source and destination." << endl;
    } else {
        cout << "Shortest path: ";
        for (int vertex : shortest_path) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
