#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, E, K;
    cin >> N >> E >> K;

    vector<vector<pair<int,int>>> adj(N + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});   // directed edge
    }

    const int INF = 1e9;
    vector<int> dist(N + 1, INF);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) {
            cout << -1;
            return 0;
        }
        maxTime = max(maxTime, dist[i]);
    }

    cout << maxTime;
}
