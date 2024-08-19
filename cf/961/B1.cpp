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
    ll n,m ;
    cin >> n >> m;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    map<ll,ll> myMap;
    for(int i=0;i<n;i++){
      myMap[v[i]]++;
    }
    vi newv(n);
    for(int i=0;i<n;i++){
      newv.pb(myMap[v[i]]*v[i]+max(myMap[v[i]-1]*(v[i]-1), myMap[v[i]+1]*(v[i]+1))
    }
    sort(newv.begin(), newv.end());
    if(newv[0] > m){
        cout << m << endl;
      }
    else cout << newv[0] << endl;
  }

}


