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

    int n, q;
    cin >> n >> q;
    vector<vector<ll>> graph(4, vector<int>(n+1, 0))
    int Y=0;
    int R=0;
    int G=0;
    int B=0;
    for(int i=1;i<=n;i++){
      string s;
      cin >> s;
      if(s[0] == 'Y' || s[1] == 'Y'){
        Y++;
      }
      if(s[0] == 'R' || s[1] == 'R'){
        R++;
      }
      if(s[0] == 'G' || s[1] == 'G'){
        G++;
      }
      if(s[0] == 'B' || s[1] == 'B'){
        B++;
      }
      graph[0][i]=R;
      graph[1][i]=G;
      graph[2][i]=B;
      graph[3][i]=Y;
    }
    vi input(2);
    for(int i=0;i<n;i++){
      cin >> v[0] >> v[1];
      sort(v.begin(), v.end());
      int flag=0;
      for(int i=0;i<4;i++){
        // check if any colour is the same
        if(graph[i][v[0]] != graph[i][v[0]-1] && (graph[i][v[1]] != graph[i][v[1]-1])){
          cout << v[1]-v[0] << endl
            flag=1;
            break;
        }
      }
      if(!flag){
        for(int i=0;i<4;i++){
          //checks which colour the current point is and if its possible to change in between
          if(graph[i][v[0]] == graph[i][v[0]-1])){
            if(graph[i].find_if(graph[i][v[0]], graph[i][v[1]],  != graph[i][v[0]])){
              cout << v[1]-v[0] << endl;
              flag=1;
              break;
            }
          }
        }
      }
      if(!flag){
        // find the closest point where the colour changes
        ll min_dist=n+1;
        for(int i=0;i<4;i++){
          if(graph[i][v[0]] == graph[i][v[0]]){
            idx=find();
            calc = v[0] - idx;
            min_dist=min(min_dist, calc);
          }
          if(graph[i][v[1]] == graph[i][v[1]]){
            idx = find();
            calc = idx-v[1] ;
            min_dist=min(min_dist, calc);
          }
        }
        cout << 2 * min_dist + (i-j) << endl;
      }
      
    }
  }

}


