#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9 + 7
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
    set<ll> subs;
    subs.clear(); 

    for (int i = 1; i <= n / 2; i++) {
      subs.insert(2 * (n - 2 * i + 1));
      sum += 2 * (n - 2 * i + 1);
    }

    if (k % 2 == 1 || k > sum) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      vi v(n);
      for (int i = 0; i < n; i++) {
        v[i] = i + 1;
      }
      ll changed = 0;
      while (k) {
        auto it = subs.end();
        it--;
        if (*it <= k) {
          int i = (n - *it / 2) / 2;
          swap(v[i], v[n - i - 1]);
          changed = i;
          k -= *it;
          subs.erase(it);
        } else {
          if (changed + 1 < n) { 
  swap(v[changed], v[changed + 1]);
};
          break;
        }
      }
      for (auto it : v) {
        cout << it << " ";
      }
      cout << endl;
    }
  }
}
