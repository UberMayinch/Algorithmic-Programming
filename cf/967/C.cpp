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
  ll t;
  cin >> t;
  while(t--){
    vector<vector<int>> G(n, vector<int>v(0));
    int n;
    cin >> n;
    int flag=0;
    int queries= 15*n;
    int prev_query=n;
    vi edges(n, 0);
    while((queries--) && (!flag)){
        found=0;
        int idx=0;
        int start=prev_query;
        int node=0;
        while(!found){
         cout << "? " << idx+1 << " " << start << endl;
          cin >> node;
          if(node == start){
            found=1;
            G[i].push_back(node);
            G[node].push_back(i);
            edges[i] =1;
          }
          else{
            prev_query = start;
            start= node;
          }
        }
        if(edges.find(0) == edges.npos()){
        flag=1;
      }
      }
      cout << "! ";
      for(int i = 0;i<n;i++){
        for(auto it: G[i]){
        cout << i+1 << " " << it << " ";
      }
      }  
    }

  }

}


