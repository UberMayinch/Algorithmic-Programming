#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
typedef vector <ll> vi;

vector <ll> solve(vector<vector<int>> graph, int nodes){
  vector<bool> visited(nodes+1, false);
  // for(auto it: visited){
  //   cout << it << " ";
  // }
  vi ans;
  vi empty;
  vector<int> fringe;
  for(int i=1;i<nodes+1;i++){
    if(visited[i] == false){
      visited[i]=true;
      ans.pb(i);
      cout << i << ": ";
      for(auto neigh: graph[i]){
        cout << neigh << " ";
        if(visited[neigh] == false)
        fringe.pb(neigh);
      }
      cout << endl;
    }
    // for(auto it: ans){
    //   cout << it << " ";
    // }
    cout << fringe.size();
    while(fringe.size() != 0){
      int x = fringe.back();
      fringe.pop_back();
      if(visited[x] == true){
        for(auto it: fringe){
          cout << "fringe";
          cout << x << ": " <<  it << " ";
        }
        cout << "false";
        return empty;
      }
      else{
        visited[x] = true;
        ans.pb(x);
        for(auto neigh: graph[x]){
          fringe.pb(neigh);
        }
      }
      }
    }
  return ans;
}
  
int main(){
  ll n, m;
  cin >> n >> m;
  vector<vector<int>>v(n+1);
  int src, dest;
  for(int i=0;i<m;i++){
    cin >> src >> dest;
    v[src].pb(dest);
  }

  vi ans = solve(v, n); 
  for(auto it= ans.rbegin(); it != ans.rend(); ++it){
    cout << *it << " ";
  }
}
