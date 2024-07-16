#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<long long int,long long int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<pair<ll,ll>> G[n+1];
  for(int i=0;i<m;i++){
    ll src, tgt, cost;
    cin >> src >> tgt >> cost;
    G[src].pb(mp(tgt, cost));
  }
  vector<vi>dist(n+1,vector<ll>(k, LLONG_MAX));
  priority_queue<pii,vector<pii>, greater<pii>> H;
  dist[1][0]=0;
  H.push({1,0});
  while(!H.empty()){
    pair<ll,ll> node = H.top();
    H.pop();
    for(auto it: G[node.first]){
      if(node.second+it.second < dist[it.first][k-1]){
        dist[it.first][k-1] = node.second+it.second;
        H.push(mp(it.first, dist[it.first][k-1]));
        sort(dist[it.first].begin(), dist[it.first].end());
      }
    }
  }
  for(auto it: dist[n]){
    cout << it << " ";
  }

}


