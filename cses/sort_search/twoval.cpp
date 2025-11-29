#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<long long int,long long int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){

  ll n, m;
  cin >>n >> m;
  vi v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  map<ll,ll> s;
  int flag=0;
  for(int i=0;i<n;i++){
    s[m-v[i]] = i;
  }
  for(int i=0;i<n;i++){
    if(s[v[i]] != i && s[v[i]] != 0){
      cout << i+1 << " " << s[v[i]]+1 << endl;
      flag=1;
      break;
    }
  }

  if(!flag){
    cout << "IMPOSSIBLE" << endl;
  }

}


