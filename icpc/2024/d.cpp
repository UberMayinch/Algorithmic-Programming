#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vi dp(ll(4e6));
  ll n = ll(4e6+1);
  for(int i=0;i<n;i++){
    if(i % 4) dp[i]=0;
    else dp[i]=1;
  }

  for(int i=0;i<n;i++){
    ll idx=4;
    // cout << i << endl;
  }

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    if(n % 4){
        cout << 0 << endl;
    }
    else{
    ll count = 1;
    ll idx = 4;
    
    for(int j=3;idx <= n;j++){
        idx = ll(pow(2, j)*(j-1));
        count += (n / idx)*(j-2);
    }
    cout << count << endl;
    }
  }
}