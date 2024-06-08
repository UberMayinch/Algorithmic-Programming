#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;
int seg[8 * 100005];

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void build(int ind, int low, int high, const vector<ll>& a, int* seg) {
    if (low == high) {
        seg[ind] = a[low];
        return;
    } else {
        int left = ind * 2 + 1;
        int right = ind * 2 + 2;
        int mid = low + (high - low) / 2;
        build(left, low, mid, a, seg);
        build(right, mid + 1, high, a, seg);
        seg[ind] = min(seg[left], seg[right]);
        return;
    }
}

int query(int* seg, int ind, int low, int high, int l, int r) {
    if (low >= l && high <= r) {
        return seg[ind];
    }
    if (high < l || low > r) {
        return INT_MAX;
    }
    int mid = low + (high - low) / 2;
    return min(query(seg, 2 * ind + 1, low, mid, l, r), query(seg, 2 * ind + 2, mid + 1, high, l, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build(0, 0, n - 1, v, seg);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;  // Convert to zero-indexed
        r--;  // Convert to zero-indexed
        cout << query(seg, 0, 0, n - 1, l, r) << "\n";
    }
    return 0;
}
