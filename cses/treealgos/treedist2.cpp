#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void diameter(int i, vector<vector<int>> &G, vector<ll>& distance) {
    stack<pair<ll, ll>> S;
    ll dist_max = 0;
    int len = G.size(); 
    vi visited(len, -1);
    
    S.push(mp(0, i));
    visited[i] = 1;
    
    while (!S.empty()) {
        pair<ll, ll> node = S.top(); S.pop();
        ll n = node.second;
        ll dist = node.first;
        dist_max = max(dist, dist_max);
        visited[n] = 1;

        if (distance[n] != -1) {
            distance[i] = dist + distance[n];
            return;
        }

        for (auto it : G[n]) {
            if (visited[it] != 1) {
                S.push(mp(dist + 1, it));
            }
        }
    }
    distance[i] = dist_max;
    return;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x); // Add this line to make the graph undirected
    }
  
    vi dist(n + 1, -1); // Initialize dist with size n+1
    for (int i = 1; i <= n; i++) {
        diameter(i, G, dist);
    }
    for (int i = 1; i <= n; i++) { // Loop should be from 1 to n to print correct distances
        cout << dist[i] << " ";
    }
}
