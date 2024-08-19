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
    ll n, s, m;
    cin >> n >> s >> m;
    ll r_prev=0;
    ll l_new;
    ll l, r;
    int flag=0;
    for(int i=0;i<n;i++){
      cin >> l >> r;
      if(l - r_prev >= s){
        flag=1;
      }
      r_prev=r;
    }
    if(m - r_prev >= s){
      flag=1;
    }
    if(flag){
      cout << "YES" << endl;
    }
    else cout << "NO" << endl;

  }

}


