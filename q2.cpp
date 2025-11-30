#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;

void dfs(int u) {
    visited[u] = 1;
    cout << u << " ";

    for(int v : adj[u]) {
        if(!visited[v]) dfs(v);
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    adj.assign(n, {});
    visited.assign(n, 0);

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int start;
    cout << "Enter start for DFS: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);
}
