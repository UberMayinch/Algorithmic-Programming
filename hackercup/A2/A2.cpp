#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<int> dsu_parent, dsu_size;

int find_set(int v) {
    if (v == dsu_parent[v]) return v;
    return dsu_parent[v] = find_set(dsu_parent[v]);
}

void dsu_init(int n) {
    dsu_parent.resize(n);
    dsu_size.assign(n, 1);
    iota(dsu_parent.begin(), dsu_parent.end(), 0);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (dsu_size[a] < dsu_size[b]) swap(a, b);
        dsu_parent[b] = a;
        dsu_size[a] += dsu_size[b];
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for(int tc=1; tc<=t; tc++){
        int n; cin >> n;
        vector<long long> v(n+1);
        for(int i=1; i<=n; i++) cin >> v[i];
        
        vector<array<ll,3>> edges;
        
        for(int i=1; i<=n; i++)
            edges.push_back({v[i], 0, i});
        
        for(int i=1; i<n; i++)
            edges.push_back({abs(v[i]-v[i+1]), i, i+1});
        
        sort(edges.begin(), edges.end());
        
        dsu_init(n+1);
        int comps = n+1;
        long long ans = 0;
        
        for(auto &e : edges){
            long long w = e[0];
            int u = e[1], v = e[2];
            if (union_sets(u, v)) {
                ans = max(ans, w);
                if (comps-- == 1) break;
            }
        }
        
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}
