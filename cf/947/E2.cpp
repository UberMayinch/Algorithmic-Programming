#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void bfs(int start_idx, vector<vector<int>>& graph, vector<int>& v) {
    queue<int> q;
    vector<int> visited(graph.size()+1);

    q.push(start_idx);
    v[start_idx-1] = 0; 
    visited[start_idx]=1;
    
    while (!q.empty()) {
        int node = q.front()-1;
        q.pop();
        visited[node] = 1; 

        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 0) { // if neighbor is still 1, visit it
                v[neighbor-1] = 0; // mark as visited
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        vector<vector<int>> graph(n+1);
        for (int i = 0; i < n-1; i++) {
            int src, dest;
            cin >> src >> dest;
            graph[src].pb(dest); 
        }
        for(int i=0;i<q;i++){
          int tog;
          cin >> tog;
          v[tog-1] +=1;
          v[tog-1]=v[tog-1] %2;
        }  

        int start_idx = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                start_idx = i+1;
                break;
            }
        }

        if (start_idx != -1) {
            bfs(start_idx, graph, v);
        }

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
