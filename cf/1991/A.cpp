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
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    if(n == 1){
      cout << v[0] << endl;

    }
    else{
      ll mx=v[0];
      for(int i=0;i<n;i++){
        if(i % 2 != 1)
        mx=max(mx, v[i]);
      }
      mx = max(mx, v[n-1]);
      cout << mx << endl;
    }

  }

}


