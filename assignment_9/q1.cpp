#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n);
    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    int src;
    cout << "Enter source for BFS: ";
    cin >> src;

    vector<int> visited(n, 0);
    queue<int> q;

    visited[src] = 1;
    q.push(src);

    cout << "BFS Traversal: ";
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}
