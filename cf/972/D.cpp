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
      cout << 0 << endl;
    }
    else{
      int start=0;
      if(v[0] <= v[1]){
        start = 1;
      }
      for(int i=start;i<n-1;i++){
        ll sum =  (v[i]+v[i+1]);
        v[i+1] = sum /2;
        v[i] = sum - v[i+1];
      }
      for(int i=n-1;i>start;i--){
        ll sum = (v[i]+v[i-1])/2;
        v[i] = sum/2;
        v[i-1] = sum - v[i];
      }
      ll mx=0;
      ll mn=10000000000001;
      for(int i=0;i<n;i++){
        if(v[i] < mn){
          mn=v[i];
        }
        if(v[i]>mx){
          mx=v[i];
        }
      }
      cout << mx - mn << endl;
    }


  }

}


