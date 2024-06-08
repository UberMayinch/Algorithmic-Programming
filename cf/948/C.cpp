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
    int n;
    cin >>n;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    vector <pair<ll,ll>> dp(n);
    dp.pb(mp(0, v[0]));
    for(int i=1;i<n;i++){
      if(v[i] % dp[i-1].second == 0){
        dp[i] = dp[i-1];
        dp[i].second = v[i];
      }
      else{
        dp[i] = mp(dp[i-1].first+1, (dp[i-1].second*v[i] / gcd(v[i], dp[i-1].second)));
      }
    }
    cout << dp[n-1].first << endl;
  }

}


