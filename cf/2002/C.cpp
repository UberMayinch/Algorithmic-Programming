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
    cin >> n;
    vector<pair<ll,ll>> centres(n);
    ll x,y;
    for(int i=0;i<n;i++){
      cin >> x >> y;
      centres[i] = mp(x,y);
    }
    pair<ll,ll> src;
    pair<ll,ll> dest;
    cin >> src.first >> src.second;
    cin >> dest.first >> dest.second;
    ll time = ((dest.first-src.first)*(dest.first-src.first) + (src.second-dest.second)*(src.second-dest.second));
    ll dist = LLONG_MAX;
    for(int i=0;i<n;i++){
      pair<ll,ll>src2 = centres[i];
      dist = min(dist,((dest.first-src2.first)*(dest.first-src2.first) + (src2.second-dest.second)*(src2.second-dest.second)));
    }
    if(dist <= time){
      cout << "NO" << endl;
    }
    else cout << "YES" << endl;

  }

}


