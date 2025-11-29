#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef vector<long long> vi;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        bool all_good = true;
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1] % v[i] != 0) {
                all_good = false;
                break;
            }
        }

        if (all_good) {
            cout << 1 << endl;
            continue;
        }

        int idx = 0;
        for (; idx < n - 1; idx++) {
            if (v[idx + 1] % v[idx] != 0)
                break;
        }

        vector<ll> divs;
        for (ll i = 1; i * i <= v[idx]; i++) {
            if (v[idx] % i == 0) {
                divs.push_back(i);
                if (i != v[idx] / i)
                    divs.push_back(v[idx] / i);
            }
        }
        sort(divs.begin(), divs.end());

        ll lo = 0, hi = divs.size() - 1, ans = 1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            bool is_valid=true;
            int f = divs[mid];
            for (int i = 0; i < n - 1; i++) {
            if ((v[i + 1] * f) % v[i] != 0) {
                is_valid=false;
            }
            }
            if (is_valid) {
                ans = divs[mid];
                hi = mid - 1;  
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }
}
