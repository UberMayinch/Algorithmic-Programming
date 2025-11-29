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
  ll n;
  cin >> n;
  vi v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  vi dp(n);
  dp[0]=0;
  dp[1]=abs(v[1]-v[0]);
  for(int i=2;i<n;i++){
    dp[i]=min(dp[i-1] + abs(v[i]-v[i-1]), dp[i-2] + abs(v[i]-v[i-2]));
  }
  cout << dp[n-1] << endl;

}