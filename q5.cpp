#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;

void dfs(int node) {
    visited[node] = 1;
    for (int v : adj[node]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    adj.assign(V, {});
    visited.assign(V, 0);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }

    cout << components;
}
