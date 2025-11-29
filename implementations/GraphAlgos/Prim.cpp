#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> G(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<bool> vis(n+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 

    pq.push({0, 1}); // start at node 1
    int totalCost = 0;
    vector<pair<int,int>> mstEdges;

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        totalCost += w;

        for (auto [v, wt] : G[u]) {
            if (!vis[v]) {
                pq.push({wt, v});
                mstEdges.push_back({u, v});
            }
        }
    }

    cout << "MST cost = " << totalCost << "\n";
    for (auto [u, v] : mstEdges) {
        cout << u << " " << v << "\n";
    }
}
