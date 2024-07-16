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
        }
        for (ll i = 0; i < n; i++) {
            cin >> c[i];
        }

        // Custom comparator for the priority queue
        auto comp = [](const tuple<ll, ll, ll>& lhs, const tuple<ll, ll, ll>& rhs) {
            return get<1>(lhs) > get<1>(rhs);
        };

        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, decltype(comp)> pq(comp);
        for (ll i = 0; i < n; i++) {
            pq.push(make_tuple(a[i], c[i] + 1, c[i]));
        }

        ll turn = 1;
        while (hp > 0) {
            auto info = pq.top();
            ll a_val = get<0>(info);
            ll t = get<1>(info);
            ll c_val = get<2>(info);
            turn = t;
            ll dmg = 0;

            while (!pq.empty() && get<1>(pq.top()) == turn) {
                auto next_info = pq.top();
                pq.pop();
                ll next_a_val = get<0>(next_info);
                ll next_t = get<1>(next_info);
                ll next_c_val = get<2>(next_info);
                dmg += next_a_val;
                pq.push(make_tuple(next_a_val, next_t + next_c_val, next_c_val));
            }


            hp -= dmg;
        }

        cout << turn << endl;
    }
    return 0;
}
