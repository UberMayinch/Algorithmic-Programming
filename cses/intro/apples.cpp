#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back
typedef vector<long long int> vi;
typedef long long int ll;

void generateBitmasks(vector<vi>& bitmasks, vi mask, int idx, int n) {
    if (idx == n) {
        bitmasks.pb(mask);
        return;
    } else {
        mask[idx] = 1;
        generateBitmasks(bitmasks, mask, idx + 1, n);
        mask[idx] = 0;
        generateBitmasks(bitmasks, mask, idx + 1, n);
    }
}

int main() {
    int n;
    cin >> n;
    vi v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    vector<vi> bitmasks;
    vi mask(n, 0);
    generateBitmasks(bitmasks, mask, 0, n);

    ll minim = LLONG_MAX;
    for (auto it : bitmasks) {
        ll sub_sum = 0;
        for (int i = 0; i < n; i++) {
            if (it[i] == 1) sub_sum += v[i];
        }
        if (sum - 2 * sub_sum >= 0)
            minim = min(sum - 2 * sub_sum, minim);
    }

    cout << minim << endl;
    return 0;
}
