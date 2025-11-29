#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        vector<pair<int, int>> ops;

        // Normalize: make a[i] <= b[i] with op 3
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
                ops.emplace_back(3, i + 1);
            }
        }

        // Sort a with op 1 (optimize by only swapping if it improves both)
        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());
        unordered_map<int, int> pos_a;
        for (int i = 0; i < n; ++i) pos_a[sorted_a[i]] = i;

        bool changed;
        do {
            changed = false;
            for (int i = 0; i + 1 < n; ++i) {
                int ai = a[i], aj = a[i + 1];
                if (ai > aj) {
                    // Check if swap helps either
                    int pi = pos_a[ai], pj = pos_a[aj];
                    if (abs(pi - (i+1)) < abs(pi - i) || abs(pj - i) < abs(pj - (i+1))) {
                        swap(a[i], a[i + 1]);
                        swap(b[i], b[i + 1]);  // op 1 affects both
                        ops.emplace_back(1, i + 1);
                        changed = true;
                    }
                }
            }
        } while (changed);

        // Sort b with op 2 (optimize similarly)
        vector<int> sorted_b = b;
        sort(sorted_b.begin(), sorted_b.end());
        unordered_map<int, int> pos_b;
        for (int i = 0; i < n; ++i) pos_b[sorted_b[i]] = i;

        do {
            changed = false;
            for (int i = 0; i + 1 < n; ++i) {
                int bi = b[i], bj = b[i + 1];
                if (bi > bj) {
                    int pi = pos_b[bi], pj = pos_b[bj];
                    if (abs(pi - (i+1)) < abs(pi - i) || abs(pj - i) < abs(pj - (i+1))) {
                        swap(b[i], b[i + 1]);
                        // op 2 only affects b
                        ops.emplace_back(2, i + 1);
                        changed = true;
                    }
                }
            }
        } while (changed);

        // Output
        cout << ops.size() << '\n';
        for (auto [type, i] : ops)
            cout << type << ' ' << i << '\n';
    }

    return 0;
}
