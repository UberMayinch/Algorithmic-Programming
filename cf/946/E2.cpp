#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
#define INF INT_MAX
typedef vector<long long int>vi;
typedef vector<pair<int,int>> vp;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int m, x;
    cin >> m >> x;
    vp v(m);
    vi dp;
    dp.pb(0);
    for(int i=0;i<m;i++){
      int a, c;
      cin >> a >> c;
      v[i]=mp(a, c);
      for(int j=0;j<c;j++){
        dp.pb(-1);
      }
    }
    for(int i=0;i<m;i++){
      for(int j=dp.size()-1;j>=0;j--){
        // cout << dp[7] << " ";
        if(dp[j] >= v[i].first){
          dp[j+v[i].second]=max(dp[j]-v[i].first+x, dp[j+v[i].second]);
          // cout << v[i].second << " " << j << " ";
          // cout << "(" << dp[j+v[i].second] << "," << j+v[i].second << ") ";
        }
        if(dp[j] != -1){
          dp[j]+=x;
        }
      }
    }
    int ans=0;
    for(int i=0;i<dp.size();i++){
      if(dp[i] != -1){
        ans = max(ans,i);
        // cout << i << " " << dp[i] << endl;
      }
    }
    cout << ans << endl;
  }

}


