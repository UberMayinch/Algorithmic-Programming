#include <bits/stdc++.h>

using namespace std;

void toposort(vector <int>* arr, int nodes, int src, int* visited){
  visited[src]=1;
  for(auto nei: arr[src]){
    if(visited[nei] == 0){
      toposort(arr, nodes, nei, visited);
    }
    cout << src << " ";
  } 
  return;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector <int> g[n+1];
  for(int i=0;i<m;i++){
    int src, dest;
    cin >> src >> dest;
    g[src].push_back(dest);
  }
  int src;
  cin >> src;
  int visited[n+1];
  for(int i=0;i<n;i++){
    visited[i]=0;
  }
  toposort(g, n, src, visited);
}
