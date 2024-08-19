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
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vi a(n);
        vi b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<pair<ll,ll>> v;
        for(int i = 0; i < n; i++) {
            v.pb(mp(a[i], b[i]));
        }
        sort(v.begin(), v.end());
        int flag = 0;
        ll max_val = 0;
        int checker = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(v[i].second == 1) {
                flag = 1;
                if(v[i].first + k > v[n-1].first) {
                    max_val = v[i].first + k;
                    v.erase(v.begin() + i);
                    if (!v.empty()) {
                        max_val += v[n/2 - 1].first;
                    }
                }
                else {
                    max_val = v[n-1].first;
                    v.erase(v.end() - 1);
                    checker = 1;
                }
                break;
            }
        }
        int i = n/2-1;
        ll change;
        if(checker) {
            while(k > 0 && i >= 0) {
                if(v[i].second == 1) {
                    if(k > v[n/2 - 1].first - v[i].first) {
                        change = min(k, v[min((size_t)(n/2), v.size() - 1)].first - v[i].first);
                        max_val += change;
                        v.insert(v.begin() + i + 1, mp(v[i].first + change, 1));
                        v.erase(v.begin() + i);
                        k -= change;
                    }
                }
                i--;
            }
        }
        
        cout << max_val << endl;
    }
    return 0;
}
