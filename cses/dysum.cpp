#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;
ll seg[8 * 100005];

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void build(ll* seg, int idx, int low, int high, const vector<ll>& a) {
    if (low == high) {
        seg[idx] = a[low];
    } else {
        int mid = (low + high) / 2;
        build(seg, 2 * idx + 1, low, mid, a);
        build(seg, 2 * idx + 2, mid + 1, high, a);
        seg[idx] = seg[2 * idx + 1]+seg[2 * idx + 2];
    }
    return;
}

long long int query(long long int* seg, int idx, int low, int high, int l, int r) {
    if (low >= l && high <= r) {
        return seg[idx];
    } else if (low > r || high < l) {
        return 0;
    } else {
        int mid = (low + high) / 2;
        return query(seg, 2 * idx + 1, low, mid, l, r)+query(seg, 2 * idx + 2, mid + 1, high, l, r);
    }
}

void update(long long int* seg, int idx, int low, int high, int node, int val) {
    if (low == high) {
        seg[idx] = val;
    } else {
        int mid = (low + high) / 2;
        if (mid >= node) {
            update(seg, 2 * idx + 1, low, mid, node, val);
        } else {
            update(seg, 2 * idx + 2, mid + 1, high, node, val);
        }
        seg[idx] = seg[2 * idx + 1]+seg[2 * idx + 2];
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t, q;
    cin >> t >> q;
    
    vi v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }
    
    build(seg, 0, 0, t - 1, v);
    
    for (int i = 0; i < q; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        if (n == 2) {
            cout << query(seg, 0, 0, t - 1, a - 1, b - 1) << endl;
        } else {
            update(seg, 0, 0, t - 1, a - 1, b);
            v[a - 1] = b; 
        }
    }
    
    return 0;
}
