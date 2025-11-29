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
  ll n, k;
  cin >> n >> k;
  vi v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  vi pre(n+1);
  pre[0] = 0;
  for(int i=1;i<n+1;i++){
    pre[i]=pre[i-1]+v[i-1];
  }
  ll count=0;
  map<ll,ll> a;
  for(int i=0;i<n+1;i++){
    count += a[pre[i]];
    a[k + pre[i]]++;
  }
  cout << count << endl;



}


