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
    int q;
    int n;
    cin >> n >> q;
    vi par(n);
    par[0]=1;
    for(int i=1;i<n;i++){
      cin >> par[i];
    }
    vi p(n);
    for(int i=0;i<n;i++){
      cin >> p[i];
    }
    int flag=0;
    // checking in O(n) if permutation is valid dfs order
      if(p[0] != 1){
        flag =1;
        break;
      }
    stack<int> S;
    S.push(1);
    for(int i=1;i<n;i++){
        cout << subtree_par << endl;
        if(S.empty()){
        flag=1;
        break;
        }
        else if(par[p[i]-1] == p[i-1]){
          S.push(p[i-1]);
        }
        else{
          while(!S.empty() && par[p[i]-1] != S.top()){
            S.pop();
        }
        }

    }
    cout << flag << endl;

    int l, r;
    for(int i=0;i<q;i++){
      cin >> l >> r;
      swap(p[l-1], p[r-1]);
      for(auto it: p){
        cout << it << " ";
      }
      cout << endl;
      if(par[p[l-1]-1] == par[p[r-1]-1] && par[p[l-1]-1] != 1){
          //flag doesn't change;
      }
      else{
    // checking in O(n) if permutation is valid dfs order
      if(p[0] != 1){
        flag =1;
        break;
      }
    stack<int> S;
    S.push(1);
    for(int i=1;i<n;i++){
        cout << subtree_par << endl;
        if(S.empty()){
        flag=1;
        break;
        }
        else if(par[p[i]-1] == p[i-1]){
          S.push(p[i-1]);
        }
        else{
          while(!S.empty() && par[p[i]-1] != S.top()){
            S.pop();
        }
        }

    }
      }
      if(flag){
        cout << "NO" << endl;
      }
      else cout << "YES" << endl;
    }

  }

}


