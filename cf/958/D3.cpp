#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;

void BFS(vector<vi>& graph, vector<bool>& visited, vi& even, vi& odd, int src) {
    bool is_odd = true;
    queue<int> neighs;
    neighs.push(src);
    visited[src] = true;
    while (!neighs.empty()) {
        int node = neighs.front();
        neighs.pop();
        
        for (auto it : graph[node]) {
            if (!visited[it]) {
                visited[it] = true;
                neighs.push(it);
        if (is_odd) odd.pb(node);
        else even.pb(node);
            }
        }
    }
}

void solve(ll& sum, vector<vi>& graph, vi& vals, int n) {
    ll evensum = 0, oddsum = 0; 

    vi even, odd;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            BFS(graph, visited, even, odd, i);
        }
    }

    for (auto it : even) {
        evensum += vals[it - 1];
    }
    for (auto it : odd) {
        oddsum += vals[it - 1];
    }
    sum += max(evensum, oddsum);

    // Determine nodes to remove
    vi nodesToRemove = (evensum > oddsum) ? even : odd;
    for (auto node : nodesToRemove) {
        vals[node - 1] = 0;  // Mark node as removed
        for (auto neighbor : graph[node]) {
            graph[neighbor].erase(remove(graph[neighbor].begin(), graph[neighbor].end(), node), graph[neighbor].end());
        }
        graph[node].clear();
    }

    // Check if there are still nodes in the graph
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (!graph[i].empty()) {
            flag = true;
            break;
        }
    }

    // Recursive call
    if (flag) {
        solve(sum, graph, vals, n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi vals(n);
        for (int i = 0; i < n; ++i) {
            cin >> vals[i];
        }
        vector<vi> graph(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int src, dest;
            cin >> src >> dest;
            graph[src].pb(dest);
            graph[dest].pb(src);
        }
        ll sum = 0;
        solve(sum, graph, vals, n);
        cout << "Sum of removed nodes: " << sum << endl;
    }
    return 0;
}
