#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define mp make_pair
#define pii pair<long long int,long long int>
typedef vector<long long int> vi;
typedef long long int ll;
const ll MOD = 1e9+7;

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

  vector<priority_queue<ll>> dist(n+1);
  priority_queue<tuple<ll,ll>> H;
  
  dist[1].push(0);
  H.push({0, 1});
  
  while(!H.empty()){
    auto [current_distance, u] = H.top();
    H.pop();
    current_distance = -current_distance; // Convert to positive distance

    for(auto it: G[u]){
      ll v = it.first;
      ll weight = it.second;
      ll new_distance = current_distance + weight;
      
      if(dist[v].size() < k || new_distance < dist[v].top()){
        if(dist[v].size() == k) dist[v].pop();
        dist[v].push(new_distance);
        H.push({-new_distance, v});
      }
    }
  }

  vector<ll> result;
  while(!dist[n].empty()){
    result.push_back(dist[n].top());
    dist[n].pop();
  }
  sort(result.begin(), result.end());
  
  for(auto it: result){
    cout << it << " ";
  }
}
