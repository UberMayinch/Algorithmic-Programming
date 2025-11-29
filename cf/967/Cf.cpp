#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
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
    int queries = 15 * n;
    int flag = 0;
    vector<vector<int>> G(n + 1);
    vector<int> known(n + 1, -1);
    int start = 1;

    while(!flag && queries > 0){
      int end = -1;
      for(int i = 1; i <= n; ++i){
        if(known[i] == -1){
          end = i;
          break;
        }
      }

      if(end == -1){
        flag = 1;
        break;
      }

      int node = 0;
      while(queries-- > 0 && node != start){
        cout << "? " << start << " " << end << endl;
        cout.flush();
        cin >> node;

        if(node == start){
          G[start].pb(end);
          G[end].pb(start);
          known[end] = 1;  
          break;
        } else {
          end = node;
        }
      }
      start = end;  
    }

    cout << "! ";
    for(int i = 1; i <= n; i++){
      for(int j : G[i]){
        cout << j << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
