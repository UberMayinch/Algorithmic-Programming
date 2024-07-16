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
    ll n, c;
    cin >> n >> c;
    ll mx=0;
    ll idx=0;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
      if(v[i] > mx){
        idx = i;
      }
      mx = max(mx, v[i]);
    }
    ll sum=c;
    for(int i=0;i<n;i++){
      sum+=v[i];
      if((v[i] == mx) && (v[i] > v[0]+c) && (i == idx)){
        cout << "0" << " ";
      }
      else if(sum > mx){
        cout << i << " ";
      }
      else cout << i + 1 << " ";
    }

    cout << endl;
  }

}


