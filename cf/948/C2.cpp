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
  while(t--){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    vector<pair<ll, ll>> dp(n);
    dp[0] = mp(0, v[0]); 
    for(int i = 1; i < n; i++){
      ll gcd_value = gcd(v[i], dp[i-1].second);
      ll lcm =  (dp[i-1].second * v[i]) / gcd_value;
      if(v.find(lcm) != npos)
      {
        dp[i] = dp[i-1];
      } 
      else {
        if(dp[i-1].first == 0){
          dp[i]=mp(2, lcm);
        }
        else{
          dp[i]=mp(dp[i-1].first+1, lcm);
        }
      }
    }
    cout << dp[n-1].first << endl;
  }
  return 0;
}
