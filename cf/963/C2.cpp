#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool check_valid(ll ans, const vi& v, int n, int k) {
    for (int i = 0; i < n; i++) {
        if ((ans - v[i]) % (2 * k) > k) {
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        ll low = v[n - 1];
        ll high = v[n - 1] + 2 * k;
        ll ans = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (check_valid(mid, v, n, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
