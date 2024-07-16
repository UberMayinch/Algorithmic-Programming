#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<ll, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll hp, n;
        cin >> hp >> n;
        vi a(n);
        vi c(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            hp -= a[i];
            cout << hp << endl;
        }
        for (ll i = 0; i < n; i++) {
            cin >> c[i];
        }

        queue<tuple<ll, ll, ll>> q;
        for (ll i = 0; i < n; i++) {
            q.push(make_tuple(a[i], c[i] + 1, c[i]));
        }

        ll turn = 1;
        while (! hp >= 0) {
            auto info = q.front();
            ll a_val = get<0>(info);
            ll t = get<1>(info);
            ll c_val = get<2>(info);
            turn = t;
            ll dmg = 0;

            while (!q.empty() && get<1>(q.front()) == turn) {
                auto next_info = q.front();
                q.pop();
                a_val = get<0>(next_info);
                t = get<1>(next_info);
                c_val = get<2>(next_info);
                dmg += a_val;
                q.push(make_tuple(a_val, t + c_val, c_val));
            }

            cout << "Turn:" << turn << " Damage: " << dmg << endl; 

            hp -= dmg;
        }

        cout << turn << endl;
    }
    return 0;
}
