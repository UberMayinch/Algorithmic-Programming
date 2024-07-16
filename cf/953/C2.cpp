#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll sum = 0;
        vector<ll> subs;
        
        for (int i = 1; i <= n / 2; i++) {
            ll value = 2 * (n - 2 * i + 1);
            subs.push_back(value);
            sum += value;
        }

        if (k % 2 == 1 || k > sum) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            vi v(n);
            for (int i = 0; i < n; i++) {
                v[i] = i + 1;
            }
            int left = 0, right = n - 1;

            while (k > 0 && left < right) {
                ll dist = 2 * (v[right] - v[left]);
                if (dist <= k) {
                    k -= dist;
                    swap(v[left], v[right]);
                    left++;
                    right--;
                } else {
                    right--;
                }
            }

            for (auto it : v) {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
