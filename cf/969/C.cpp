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
    ll n,a,b;
    cin >> n >> a >> b;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    if(gcd(a,b) == 1){
      cout << 0 << endl;
    }
    else{
      ll gd = gcd(a,b);
      for(int i=0;i<n;i++){
        v[i] %= gd;
      }
      sort(v.begin(), v.end());
      ll mn = v[n-1]-v[0];
      for(int i=n-1;i>=1;i--){
        mn = min(mn, v[i-1]-v[i]+gd);
      }

      cout << mn << endl;

    }


  }

}
