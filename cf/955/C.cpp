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
    ll n, l,r;
    cin >> n >> l >> r;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    ll cnt;
    ll sum;
    vector<pair<ll,ll>> dp(n);
    if(v[n-1] >= l) && (v[n-1] <= r){
      cnt = 1;
      sum=0;
    }
    else cnt=0;
    sum = v[n-1];
    dp[n-1]=mp(sum, cnt);
    for(int i=n-2;i>=0;i--){
      if(((dp[i+1].first + v[i] >= l) && (dp[i+1].first + v[i] <= r)) || ((dp[i] >= l) && (dp[i] <= r))){
        sum=0;
        cnt++;
      }
      else sum+=v[i];
      dp[i]=mp(sum, cnt);
    }
    cout << dp[0].second << endl;

  }

}


