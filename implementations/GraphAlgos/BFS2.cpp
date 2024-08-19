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
  int n, m;
  cin >> n >> m;
  vector <int> v[n+1];
  for(int i=0;i<m;i++){
    int src, dst;
    cin >> src >> dst;
    v[src].pb(dst);
  }
  
  vector<int> visited(n+1, 0);
  queue<int> q;
  int src;
  cout << "Enter Source for BFS" << endl;
  cin >> src;
  q.push(src);
  while(!q.empty()){
    int vert = q.front();
    q.pop();
    if(visited[vert] != 1){
      cout << vert << endl;
      visited[vert]=1;
      for(auto it: v[vert]){
        q.push(it);
      }
    }

  }
}


