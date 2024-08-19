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
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    ll score=0;
    ll changeable=0;
    for(int i=0;i<n;i++){
      if(i % 2 == 0){
        score+=v[i];
      }
      if(i % 2){
        score -=v[i];
        changeable+=v[i-1]-v[i];
      }
    }
    ll z=0;
    changeable = min(k, changeable);
    cout << max(z, score-changeable) << endl;

  }

}


