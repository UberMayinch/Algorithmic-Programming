#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll highest_bit = 0;
        for (ll i = 63; i >= 0; --i) {
            if ((r & (1LL << i)) && !(l & (1LL << i))) {
            highest_bit = i;
            break;
            }
        }
        ll max_xor = (1LL << (highest_bit + 1)) - 1;
        ll a = max_xor;
        ll b = max_xor - 1;
        ll c = l;
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
