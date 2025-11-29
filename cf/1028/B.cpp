#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<ll> pow2 = {1};

    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n), q(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> q[i];

        if ((int)pow2.size() <= n) {
            int old = pow2.size();
            pow2.resize(n+1);
            for (int k = old; k <= n; k++) {
                pow2[k] = (pow2[k-1] * 2) % MOD;
            }
        }

        ll A1 = 0, A2 = 0, B1 = 0, B2 = 0;
        vector<ll> r(n);

        for (int i = 0; i < n; i++) {
            ll a = pow2[p[i]];
            if (a >= A1) {
                A2 = A1;
                A1 = a;
            } else if (a > A2) {
                A2 = a;
            }

            ll b = pow2[q[i]];
            if (b >= B1) {
                B2 = B1;
                B1 = b;
            } else if (b > B2) {
                B2 = b;
            }

            ll best = A1 + B1;
            best = max(best, A1 + B2);
            best = max(best, A2 + B1);

            r[i] = best % MOD;
        }

        for (int i = 0; i < n; i++) {
            cout << r[i] << (i+1<n ? ' ' : '\n');
        }
    }

    return 0;
}
