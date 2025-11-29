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
    ll n;
    cin >> n;
    vector<pair<ll,ll>> mons;
    for(ll i = 0; i < n; i++){
      ll x, y;
      cin >> x >> y;
      mons.pb(mp(x, y));
    }
    if(n == 1){
      cout << 1 << '\n';
      continue;
    }

    ll x_min1 = LLONG_MAX, x_min2 = LLONG_MAX;
    ll x_max1 = LLONG_MIN, x_max2 = LLONG_MIN;
    ll y_min1 = LLONG_MAX, y_min2 = LLONG_MAX;
    ll y_max1 = LLONG_MIN, y_max2 = LLONG_MIN;
    ll cnt_xmin1 = 0, cnt_xmax1 = 0;
    ll cnt_ymin1 = 0, cnt_ymax1 = 0;
    
    for(auto &p : mons){
      ll x = p.first;
      if(x < x_min1){ x_min2 = x_min1; x_min1 = x; cnt_xmin1 = 1; }
      else if(x == x_min1){ cnt_xmin1++; }
      else if(x < x_min2){ x_min2 = x; }
      
      if(x > x_max1){ x_max2 = x_max1; x_max1 = x; cnt_xmax1 = 1; }
      else if(x == x_max1){ cnt_xmax1++; }
      else if(x > x_max2){ x_max2 = x; }
      
      ll y = p.second;
      if(y < y_min1){ y_min2 = y_min1; y_min1 = y; cnt_ymin1 = 1; }
      else if(y == y_min1){ cnt_ymin1++; }
      else if(y < y_min2){ y_min2 = y; }
      
      if(y > y_max1){ y_max2 = y_max1; y_max1 = y; cnt_ymax1 = 1; }
      else if(y == y_max1){ cnt_ymax1++; }
      else if(y > y_max2){ y_max2 = y; }
    }
    
    ll best = (x_max1 - x_min1 + 1) * (y_max1 - y_min1 + 1);
    
    for(auto &p : mons){
      ll x = p.first;
      ll y = p.second;
      ll xmin = (x == x_min1 && cnt_xmin1 == 1 ? x_min2 : x_min1);
      ll xmax = (x == x_max1 && cnt_xmax1 == 1 ? x_max2 : x_max1);
      ll ymin = (y == y_min1 && cnt_ymin1 == 1 ? y_min2 : y_min1);
      ll ymax = (y == y_max1 && cnt_ymax1 == 1 ? y_max2 : y_max1);
      ll area = (xmax - xmin + 1) * (ymax - ymin + 1);
      best = min(best, area);
    }
    
    cout << best << '\n';
  }
  return 0;
}
