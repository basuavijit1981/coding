// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void
bfs( vector<pair<int,int>> graph[], int start, int end , int numOfVer ) {
    bool visited[ numOfVer];
    
    for( auto v: visited ) {
        visited[ v ] = false;
    }
    
    queue<int> bfsQ;

    bfsQ.push( start);
    bool isFound = false;
    while( !bfsQ.empty()) {
        auto e = bfsQ.front();
        bfsQ.pop();
        visited[ e ] = true;
        auto adj = graph[e];
        for( auto n : adj) {
            if( n.first == end ) {
                cout << "Reached destination" << endl;
                isFound = true;
                break;
            } else if( !visited[n.first ]) {
                bfsQ.push( n.first );
            }
        }
        if( isFound ) {
            break;
        }
    }

    if( !isFound) {
        cout << " could not reach end node" << endl;
    }
}
int main() {
    // Write C++ code here
    cout << "Enter number of vertices: " << endl;
    int numOfVer =0;
    int numOfEdge = 0;
    int wt;
    cin >> numOfVer;

    vector<pair<int, int> > graph[numOfVer];

    cout<<"Enter the number of edges in graph"<<endl;
    cin>> numOfEdge;

    cout << "Enter the edge details" << endl;

    for( auto i = 0; i < numOfEdge; i++ ) {
        int startVertex, endVertex;
        cin >> startVertex >> endVertex >> wt;
        
        graph[ startVertex ].push_back( make_pair(endVertex, wt ) );
    }

    for( auto i = 0; i < numOfVer; i++ ) {
        for( auto e : graph[ i ] ) {
            cout << i << " -> " << e.first << " cost: " << e.second << endl;
        }
    }
    cout << "Enter start and end node" << endl;
    int start, dest;
    cin >> start >> dest;
    bfs( graph, start, dest, numOfVer );
    return 0;
}