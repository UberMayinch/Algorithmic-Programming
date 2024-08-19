#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool isK(int k){
  return(n == k);
}

int main(){

  ll n, k;
  cin >> n >> k;
  vector<pair<ll,ll>> a;
  for(int i=0;i<n;i++){
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  int flag=0;
  for(int i=0;i<n;i++){
    if(flag)break;
    for(int j=i;j<n;j++){
      ll fid = k - a[i].first - a[j].first;
      if(ranges::find(a, fid, pair<int,int> :: first != a.end()){
        cout << i << " " << j << " " << fid;
        flag=1;
        break;
      }
      else if(a[i].first+a[j].first > k){
        cout << "IMPOSSIBLE";
        flag=1;
        break;
      }
    }
  }
}


