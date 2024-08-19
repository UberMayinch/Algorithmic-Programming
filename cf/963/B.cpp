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
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    bool odd = (v[0] % 2 == 1);
    ll ans=0;
    for(int i=0;i<n;i++){
      if(v[i] % 2 == 1){
        ans +=1;
      }
    }
    if(ans == 0){
      cout << ans << endl;
    }
    else{
      if(v[n-1] % 2){
        cout << n-ans << endl;
      }
      else {
        ll odd=0;
        ll even=0;;
        vi evens;
        for(int i=n-1;i>=0;i--){
          if(v[i] % 2 && odd == 0){
            odd = v[i];
          }
          else if(v[i] % 2 == 0 && odd){
            even += v[i];
          }
          else if(v[i] % 2 == 0 && odd == 0){
            evens.pb(v[i]);
          }
        }
        sort(evens.begin(), evens.end());
        ll sum=even+odd;
        int flag=0;
        for(int i=0;i<evens.size();i++){
          if(sum < evens[i]){
            flag=1;
            break;
          }
          sum+=evens[i];
        }
        if(flag){
            cout << n-ans+1 << endl;
        }
        else cout << n-ans << endl;
      }
    }

  }


}
