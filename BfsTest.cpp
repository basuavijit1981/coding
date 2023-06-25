#include <iostream>

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int solve(int A, vector<vector<int> > &B, int C, int D) {
    auto numOfEdges = B.size();
    int u = 0;
    auto lastPseudoVertex = A;
    vector<vector< int> > graph(2*numOfEdges);
    for( auto& edgeInfo : B) {
        auto u = edgeInfo[0];
        auto v = edgeInfo[1];
        auto weight = edgeInfo[2];
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

    for( auto i =0; i < lastPseudoVertex; i++) {
        auto adjList = graph[ i];
        cout << "Adj list of " << i <<endl;
        for( auto e: adjList) {
            cout << "  "  << e << "  " << endl;
        }
    }

    queue<int> q;
    q.push(C);

    vector<bool> visited(graph.size(), false);
    visited[C] = true;

    vector<int> parent(graph.size(), -1);

    while (!q.empty()) {
        int current_vertex = q.front();
        q.pop();

        if (current_vertex == D)
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

    if (parent[D] == -1)
        return -1;  // No path exists

    // Reconstruct the path
    int current_vertex = D;
    int pathLen = 0;
    while (current_vertex != C ) {
        pathLen++;
        cout << " Reached " << current_vertex <<endl;
        current_vertex = parent[current_vertex];
        if( current_vertex == -1) {
            pathLen = -1;
            break;
        }
    }

    return pathLen;
}


int main() {

    int num_vertices, num_edges;
    cout << "Enter the number of vertices: ";
    cin >> num_vertices;
    cout << "Enter the number of edges: ";
    cin >> num_edges;
    vector< vector<int> > B;
    cout << "Enter edge info as u v weight format " << endl;
    for( auto i = 0; i < num_edges; i++) {
        int u, v, weight;
        cin >> u >> v;
        cin >> weight;
        vector<int> edgeInfo;
        edgeInfo.push_back( u);
        edgeInfo.push_back( v);
        edgeInfo.push_back( weight);
        B.push_back( edgeInfo );
    }
    int C, D;
    cout << "Enter the source vertex: ";
    cin >> C;
    cout << "Enter the destination vertex: ";
    cin >> D;
    auto pathLen = solve( num_vertices, B, C, D);
    cout << "PathLen from " << C
         <<" to " << D << " is: " << pathLen <<endl;
    return 0;
}
