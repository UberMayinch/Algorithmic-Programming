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
    ll n, m;
    cin >> n >> m;
    ll sum=0;
    set<ll> b;
    for(int i=0;i<n;i++){
      int len;
      cin >> len;
      vi v(len);
      for(int j=0;j<len;j++){
        cin >> v[j];
      }
      b.insert(v[j]);
    }
    ll result=0;
    while(b.count(result)){
          ++result;
      }

    for(int i=0;i<=m;i++){
      sum += max(i, result);
    }
      cout << sum << endl;
  }

}


