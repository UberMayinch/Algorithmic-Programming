#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, q;
    cin >> n >> q;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    map<ll, ll> m;
    for (int i = 0; i < n ; i++)
    {
      ll num = (n * (n - 1) / 2) - ((n - 1 - i) * (n - 2 - i) / 2) - ((i - 1) * (i) / 2);
      m[num] += 1;
      if(i != n-1){
      num = (n * (n - 1)) / 2 - ((n - 1 - i) * (n - 2 - i)) / 2 - (i * (i + 1) / 2);
      m[num] += v[i + 1] - v[i] - 1;
      }
      // stuff between array elements;
    }
    for (int i = 0; i < q; i++)
    {
      ll a;
      cin >> a;
      cout << (m[a]) << " ";
    }
    cout << endl;
  }
}
