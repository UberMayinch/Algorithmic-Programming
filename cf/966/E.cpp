#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    ll n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vi v(w);
    for(int i=0;i<w;i++){
      cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    vi times(n*m);
    for(ll i=1;i<n+1;i++){
        ll len=0;
        len += min(k, n-i+1);
          len += min(k, i);
      for(ll j=1;j<m+1;j++){
        ll width=0;
        width += min(k, m-j+1);
        width += min(k, j); 
        times.pb((width-k)*(len-k));
      }
    }
    sort(times.rbegin(), times.rend());
    ll ans=0;
    for(int i=0;i<v.size();i++){
      ans+=(times[i]*v[i]);
    }
    cout << ans << endl;


  }

}


