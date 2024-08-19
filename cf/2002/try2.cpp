#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vi par(n);
        par[0] = 1;
        for (int i = 1; i < n; i++) {
            cin >> par[i];
        }
        
        vi p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        
        vi position(n + 1);
        for (int i = 0; i < n; i++) {
            position[p[i]] = i;
        }
        
        vi lastChild(n + 1, -1);
        int maxValid = 0;
        
        auto isValid = [&]() {
            if (p[0] != 1) return false;
            
            for (int i = maxValid + 1; i < n; i++) {
                int node = p[i];
                int parent = par[node - 1];
                if (position[parent] > i || lastChild[parent] > position[node]) {
                    return false;
                }
                lastChild[parent] = i;
            }
            maxValid = n - 1;
            return true;
        };
        
        cout << (isValid() ? "YES" : "NO") << '\n';
        
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            
            swap(p[l], p[r]);
            swap(position[p[l]], position[p[r]]);
            
            maxValid = min(maxValid, min(l, r));
            
            cout << (isValid() ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
