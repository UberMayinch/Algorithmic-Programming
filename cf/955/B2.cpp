#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll x, y, k;
    cin >> x >> y >> k;
    while (k > 0) {
      x++;
      k--;
      cout << x << endl;
      if (x % y == 0) {
        while (x % y == 0) {
          x /= y;
        }
      } else {
        ll remainder = x % y;
        ll steps_to_next_multiple = y - remainder;
        if (k >= steps_to_next_multiple) {
          k -= steps_to_next_multiple;
          x += steps_to_next_multiple;
        } else {
          x += k;
          k = 0;
        }
      }
    }
    cout << x << endl;
  }
}
