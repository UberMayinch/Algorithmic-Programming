#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define MOD 10000007;
typedef vector<long long int> vi;
typedef long long int ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        ll sum_a = accumulate(a.begin(), a.end(), 0LL);
        ll sum_b = accumulate(b.begin(), b.end(), 0LL);
        int max_a = *max_element(a.begin(), a.end());
        int max_b = *max_element(b.begin(), b.end());

        if (sum_a != sum_b || max_b < max_a) {
            cout << "No" << endl;
            continue;
        }


        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        int l = 0, r = n - 1;
        bool possible = true;

        for (int target : b) {
            if (l > r) {
                possible = false;
                break;
            }

            int x = a[r];
            r--;
            int remaining = target - x;

            if (remaining < 0) {
                possible = false;
                break;
            }

            vector<int> group = {x};

            while (remaining > 0 && r >= l) {
                if (a[r] <= remaining) {
                    group.pb(a[r]);
                    remaining -= a[r];
                    r--;
                } else {
                    break;
                }
            }

            while (remaining > 0 && l <= r) {
                if (a[l] <= remaining) {
                    group.pb(a[l]);
                    remaining -= a[l];
                    l++;
                } else {
                    possible = false;
                    break;
                }
            }

            if (remaining != 0) {
                possible = false;
            }

            if (!possible) {
                break;
            }

            sort(group.begin(), group.end());
            ll sum_till= 0;
            bool valid = true;
            for (size_t i = 0; i < group.size() - 1; ++i) {
                sum_till += group[i];
                if (sum_till < group[i + 1] - 1) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                possible = false;
                break;
            }
        }

        if (possible && l > r) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}