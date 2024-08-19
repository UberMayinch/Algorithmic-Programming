#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vi fact(200000, 1);
  for(int i=1;i<fact.size();i++){
    fact[i] = ((fact[i-1] % MOD) * (i % MOD)) % MOD;
  }
  ll t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    vi v(n);
    int cnt=0;
    for(int i=0;i<n;i++){
      cin >> v[i];
      if(v[i] == 1){
        cnt++;
      }
    }
    ll ans = fact[cnt] /(fact[cnt-(k+1)/2]*fact[(k+1)/2]) * (fact[n-(k+1)/2])/(fact[(k-1)/2]*fact[n-k]) ;
  cout << ans << endl;
  }

}


