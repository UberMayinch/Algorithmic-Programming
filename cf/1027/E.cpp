#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long> vi;
typedef long long ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, w;
            cin >> u >> w;
            adj[u].pb(w);
            adj[w].pb(u);
        }

        vi threat(n + 1), C(n + 1), minC(n + 1), maxC(n + 1);
        vector<int> depth(n + 1);
        stack<pair<int,int>> st;

        // Initialize root
        depth[1] = 0;
        C[1] = v[1];
        minC[1] = 0;
        maxC[1] = 0;
        threat[1] = C[1] - minC[1];
        st.push(mp(1, 0));

        while (!st.empty()) {
            auto cur = st.top();
            st.pop();
            int u = cur.first;
            int parent = cur.second;
            for (int vtx : adj[u]) {
                if (vtx == parent) continue;
                depth[vtx] = depth[u] + 1;
                ll fv = (depth[vtx] % 2 == 0 ? v[vtx] : -v[vtx]);
                C[vtx] = C[u] + fv;
                minC[vtx] = min(minC[u], C[u]);
                maxC[vtx] = max(maxC[u], C[u]);
                if (depth[vtx] % 2 == 0) {
                    threat[vtx] = C[vtx] - minC[vtx];
                } else {
                    threat[vtx] = maxC[vtx] - C[vtx];
                }
                st.push(mp(vtx, u));
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << threat[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
