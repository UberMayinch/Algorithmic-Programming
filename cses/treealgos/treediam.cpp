#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int diameter(int i, vector<vector<int>> G, ll& distance){
  stack<pair<ll,ll>> S;
  ll dist_max=0;
  ll node_max=0;
  int len = G.size(); 
  vi visited(len, -1);
  S.push(mp(0, i));
  while(!S.empty()){
    pair<ll,ll> node = S.top();S.pop();
    ll n = node.second;
    ll dist = node.first;
    if(dist > dist_max){
      node_max = n;
      dist_max = dist;
    }
    visited[n]=1;
    for(auto it: G[n]){
      if(visited[it] != 1){
      S.push(mp(dist+1,it));
      }
    }
  }
  distance = dist_max;
  return node_max;
}

int main(){
  int n;
  cin >> n;
  vector<vector<int>> G(n+1);
  for(int i=0;i<n-1;i++){
    int x, y;
    cin >> x >> y;
    G[x].pb(y);
    G[y].pb(x);
  }
  
  ll dist=0;;
  int start = diameter(1, G, dist);
  int end = diameter(start, G, dist);
  cout << dist << endl;

}


