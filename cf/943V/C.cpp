#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;

int main(){
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    n = n-1;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    vi ans(n+1);
    ans[0]=v[0]+1;
    ans[1]=v[0];
    for(int i=1;i<n;i++){
      if(v[i] >= ans[i]){
        ans[i]+= ((v[i]/ans[i-1])+1)*ans[i-1];
        ans[i+1]=v[i];
      }
      else{
        ans[i+1]=v[i];
      }
    }
    for(auto it: ans){
      cout << it << " ";
    }
    cout << endl;
  }

}

