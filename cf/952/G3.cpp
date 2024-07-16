#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<long long int, long long int>
typedef vector<long long int> vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

// Function to perform binary exponentiation
ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll allowed = (10 + k - 1) / k;
        if (k > 10) {
            allowed = 1;
        }
        ll count = power(allowed, r); 
        ll sub = (l == 0) ? 1 : power(allowed, l); 
        count = (count - sub + MOD) % MOD;
        cout << count << endl;
    }
    return 0;
}
