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
    vector <int> v(n);
    for(int i=0;i<n;i++){
      cin >> v[i]; 
    }
    vector<vector<int>> graph(n);
    for(int i=0;i<n;i++){
      int src, dest;
      cin >> src >> dest;
      graph[src-1].pb(dest);
    }
    int flag=0;
    int start_idx;
    for(int i=0;i<n;i++){
      if(v[i] == 1){
        start_idx=i;
        flag = 1;
        break;
      }
    } 
    bfs(start_idx) 
      //at each point of bfs change v[node] to 0

    for(int i=0;i<n;i++){
      if(v[i] == 1){
        flag = 1;
        break;
      }
    }
    if(flag == 1){
      cout << "No" << endl;
    }
    else cout << "Yes" << endl;
  }

}


