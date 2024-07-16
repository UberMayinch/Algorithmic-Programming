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
    ll n, l, r;
    cin >> n >> l >> r;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    vi pref(n+1);
    ll sum=0;
    pref[0]=0;
    for(int i=0;i<n;i++){
      sum+=v[i];
      pref[i+1]=sum;
    }
    ll ri=1;
    ll le=0;
    ll count=0;
    while(ri < n+1){
      if(pref[ri]-pref[le] < l){
        ri++;
      }
      else if(pref[ri]-pref[le] > r){
        le++;
      }
      else{
        count++;
        le=ri;
        ri++;
      }
    }
    cout << count << endl;
  }

}


