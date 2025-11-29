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
            cout << "No\n";
            continue;
        }


        if (max_b < max_a) {
            cout << "No\n";
            continue;
        }

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        deque<int> dq(a.begin(), a.end());
        bool possible = true;

        for (int target : b) {
            if (dq.empty()) {
                possible = false;
                break;
            }

            int x = dq.back();
            dq.pop_back();
            int remaining = target - x;

            if (remaining < 0) {
                possible = false;
                break;
            }

            vector<int> group = {x};

            while (remaining > 0 && !dq.empty()) {
                int next_x = dq.back();
                if (next_x <= remaining) {
                    dq.pop_back();
                    group.push_back(next_x);
                    remaining -= next_x;
                } else {
                    break;
                }
            }

            while (remaining > 0 && !dq.empty()) {
                int next_x = dq.front();
                if (next_x > remaining) {
                    possible = false;
                    break;
                }
                dq.pop_front();
                group.push_back(next_x);
                remaining -= next_x;
            }

            if (remaining != 0) {
                possible = false;
            }

            if (!possible) {
                break;
            }

            sort(group.begin(), group.end());
            ll sum_so_far = 0;
            bool valid = true;
            for (size_t i = 0; i < group.size() - 1; ++i) {
                sum_so_far += group[i];
                if (sum_so_far < group[i + 1] - 1) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                possible = false;
                break;
            }
        }

        if (possible && dq.empty()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}