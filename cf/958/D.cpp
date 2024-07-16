#include <bits/stdc++.h>
using namespace std;

void bfsAndRemove(vector<vector<int>>& adj, vector<int>& values, int start, long long& sum) {
    int n = adj.size();
    vector<int> layer(n, -1);
    queue<int> q;
    q.push(start);
    layer[start] = 0;
    
    long long evenSum = 0, oddSum = 0;
    vector<int> nodesAtEvenLayers, nodesAtOddLayers;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int currentLayer = layer[node];
        
        if (currentLayer % 2 == 0) {
            evenSum += values[node];
            nodesAtEvenLayers.push_back(node);
        } else {
            oddSum += values[node];
            nodesAtOddLayers.push_back(node);
        }
        
        for (int neighbor : adj[node]) {
            if (layer[neighbor] == -1) { // unvisited
                layer[neighbor] = currentLayer + 1;
                q.push(neighbor);
            }
        }
    }
    
    vector<int> nodesToRemove;
    if (evenSum > oddSum) {
        nodesToRemove = nodesAtEvenLayers;
    } else {
        nodesToRemove = nodesAtOddLayers;
    }
    
    unordered_set<int> toRemoveSet(nodesToRemove.begin(), nodesToRemove.end());
    sum += (evenSum > oddSum) ? evenSum : oddSum;
    
    for (int node : nodesToRemove) {
        values[node] = 0; // Set value to 0 to mark as removed
        for (int neighbor : adj[node]) {
            adj[neighbor].erase(remove(adj[neighbor].begin(), adj[neighbor].end(), node), adj[neighbor].end());
        }
        adj[node].clear();
    }
    
    for (int node : nodesToRemove) {
        for (int neighbor : adj[node]) {
            if (values[neighbor] != 0) { 
                bfsAndRemove(adj, values, neighbor, sum);
            }
        }
    }
}

int main() {
    int n; // number of nodes
    cin >> n;
    
    vector<vector<int>> adj(n);
    vector<int> values(n);
    
    // Read values of nodes
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    
    // Read edges
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    long long sum = 0;
    bfsAndRemove(adj, values, 0, sum);
    
    cout << "Sum of removed nodes: " << sum << endl;
    
    return 0;
}
