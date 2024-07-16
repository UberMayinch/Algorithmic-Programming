#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void BFS(vector<ll>& graph, vector<bool>& visited, vi& even, vi odd, int src){
  bool odd = true;
  queue<int> neighs;
  neighs.push(src);
  while(!neighs.empty()){
    auto src =neighs.pop()
    for(auto it: graph[src]){
    neighs.push(it);
    if(odd) odd.pb(it);
    else even.pb(it);
    odd = not odd;
    }
  }

}

void solve(ll& sum, vector<ll>* graph, vi vals){
    
    int flag=0;
    ll evensum, oddsum; 
    
    vi even, odd;
    vector <bool> visited(n+1);
    for(int i=1;i<n+1;i++){
    //try to start BFS from every node, that node becomes odd, others become even
    if(!visited[i]){
      even.pb(i);
      BFS(graph, visited, even, odd, i);
    }
      // set flag here if any node is encountered
    if(!graph[i].empty())flag=1;
    }
    
    for(auto it: even){
    evensum += vals[it-1];
  }
    for(auto it: odd){
    oddsum += vals[it-1];
  }
    sum += max(evensum, oddsum);

    //recursive call
    if(flag == 1)
    solve(sum, graph, vals);
   
    //base case
    else
      return;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi vals(n);
    for(int i=0;i<n;i++){
      cin >> vals[i];
    }
    vi graph[n+1];
    for(int i=0;i<n-1;i++){
      int src,dest;
      cin >> src >> dest;
      graph[src].pb(dest);
      graph[dest].pb(src);
    }
    ll sum=0;

  }

}


