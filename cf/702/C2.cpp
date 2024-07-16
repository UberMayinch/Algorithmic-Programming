#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
struct CustomHash {
    size_t operator()(ll x) const {
        static const ll PRIME = 31;
        return x ^ (x >> 33) ^ (x << 11) ^ (x >> 5) * PRIME;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    unordered_set<ll, CustomHash> cubes;
    const ll LIMIT = 1e10;
    const ll MAX_XY = 10000;
    for (ll x = 1; x < MAX_XY; x++) {
        for (ll y = 1; y <= x; y++) { 
            ll z = x + y;
            ll b = x * y;
            ll value = z * z * z - 3 * b * z;
            if (value > LIMIT) break;
            cubes.insert(value);
        }
    }
    cout << "cubes = {";
    bool first = true;
    for (const auto& cube : cubes) {
        if (first) {
            first = false;
        } else {
            cout << ", ";
        }
        cout << cube;
    }
    cout << "};" << endl;
    return 0;
}
