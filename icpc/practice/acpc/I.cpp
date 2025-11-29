#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

static map<ll, int> factorize(ll n) {
  map<ll, int> m;
  if (n < 2) return m;
  for (ll p = 2; p * p <= n; ++p) {
    while (n % p == 0) {
      m[p]++;
      n /= p;
    }
  }
  if (n > 1) m[n]++;
  return m;
}

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;

  auto fa = factorize(a);
  auto fb = factorize(b);

  map<ll, int> res;
  for (auto &kv : fa) {
    if (!fb.count(kv.first)) res[kv.first] = kv.second;
  }

  ll ans=1;
  bool first = true;
  for (auto &kv : res) {
    ans *= (kv.second+1);
  }
  if(ans == 1){
    cout << "0" << endl;
    return 0;
  }
  cout << ans << endl;
}