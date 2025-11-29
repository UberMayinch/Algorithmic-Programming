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
    if(n % 2){
      for(int i=0;i<n/2;i++){
        v[i]=i+1;
      }
      for(int i=1;i<=n/2;i++){
        v[n-i] = n/2+i;
      }
      v[n/2] = n;
      for(auto it: v){
        cout << it << " ";
      }
        cout << endl;
    }
    else cout << -1 << endl;

  }

}


