#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vi v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        map<ll, ll> myMap;
        for (int i = 0; i < n; i++) {
            myMap[v[i]]++;
        }
        vi newv;
        for (int i = 0; i < n; i++) {
            newv[i] = myMap[v[i]] * v[i] + max((myMap[v[i] - 1] * (v[i] - 1)), (myMap[v[i] + 1] * (v[i] + 1)));
        }
        sort(newv.begin(), newv.end());
        if (newv[n-1] > m) {
            cout << m << endl;
        } else {
            cout << newv[n-1] << endl;
        }
    }
    return 0;
}
