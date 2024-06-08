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
    vi v(n);
    ll lc=1;
    for(int i=0;i<n;i++){
      cin >> v[i];
      lc = lcm(lc,v[i]);
    }
    ll sum=0;
    vi ans(n);
    for(int i=0;i<n;i++){
      ans[i]=lc/v[i];
      sum+=ans[i];
    }
    
    if(sum >= lc){
      cout << "-1" << endl;
    }
    else{
      for(auto it: ans){
        cout << it << " ";
      }
      cout << endl;
    }
  }

}


