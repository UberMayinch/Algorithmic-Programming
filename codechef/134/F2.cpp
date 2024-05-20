#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back
#define mp make_pair 
typedef vector<long long int>vi;
typedef long long int ll;

void add_neighbours(pair<pair<int, int>, int> ele, int n, int m, queue pair<pair<int, int>, int> q){
  int i, j;
  i = ele.first.first;
  j = ele.first.second;
  turns = ele.second;
  if((i != n)){
    if(j != m){
      q.add(mp(mp(i+1, j+1), turns+1));
    }
    if(j != 0){
      q.add(mp(mp(i+1, j-1), turns+1));
    }
  }
  if((i != 0)){
    if(j != m){
      q.add(mp(mp(i-1, j+1), turns+1));
    }
    if(j != 0){
      q.add(mp(mp(i-1, j-1), turns+1));
    }
  }
  return;
}


int main(){
  ll t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    queue <pair<pair<int,int>, int>> q;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
        grid[i][j] = int(s[j])-48;
        if(grid[i][j]  == 0){
          q.push_front(mp(mp(i, j), 1));
        }
      }
    }
    int ans=0;
    while(! q.empty){
      pair<pair<int, int>, int> ele = q.pop_front;
      add_neighbours(ele, n, m, q);
      int ans = ele.second;
    } 
    cout << ans << endl;
  }

}

