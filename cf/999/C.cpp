#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;
const int MOD = 998244353;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


struct dp {
    unordered_map<int, int> cnt_map;
    int shift = 0;

    void add(int actual_cnt, int count) {
        int key = actual_cnt - shift;
        cnt_map[key] = (cnt_map[key] + count) % MOD;
    }

    int get(int actual_cnt) const {
        int key = actual_cnt - shift;
        auto it = cnt_map.find(key);
        return it != cnt_map.end() ? it->second : 0;
    }

    int sum() const {
        int res = 0;
        for (auto &[k, v] : cnt_map) {
            res = (res + v) % MOD;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        dp last0, last1;
        last0.add(0, 1); 

        for (int ai : a) {
            int honest0 = last0.get(ai);
            int honest1 = last1.get(ai);
            int honest = (honest0 + honest1) % MOD;

            dp new_last0, new_last1;

            if (honest > 0) {
                new_last0.add(ai, honest);
            }

            new_last1.cnt_map = last0.cnt_map;
            new_last1.shift = last0.shift + 1;

            last0 = new_last0;
            last1 = new_last1;

            if (last0.cnt_map.empty() && last1.cnt_map.empty()) {
                break;
            }
        }

        int total = (last0.sum() + last1.sum()) % MOD;
        cout << total << '\n';
    }
    return 0;
}