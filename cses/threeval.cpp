#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;

int main(){
  ll n, x;
  cin >> n >> x;
  vector pair<long long int, int> v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
    make_pair(v[i], i);
  }
  int flag=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        sort(v.begin(), v.end());
      }
    if(flag) break;
    }
  if(flag == 0){
    cout << "IMPOSSIBLE" << endl;
  }
}

