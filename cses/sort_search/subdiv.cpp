#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ll n;
  cin >> n;
  vi v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  vi pref(n+1);
  pref[0]=0;
  for(int i=0;i<n;i++){
    pref[i+1]=pref[i]+v[i];
  }

  for(int i=0;i<n+1;i++){
    pref[i] = (pref[i] % n + n) % n;
  }
  map<ll,ll> count;
  ll cnt=0;
  for(int i=0;i<n+1;i++){
    cnt += count[pref[i]]++;
  }
  cout << cnt << endl;


}


