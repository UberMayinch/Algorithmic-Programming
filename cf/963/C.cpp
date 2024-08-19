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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    sort(v.begin(), v.end());

    vi mods(2*k, 0);
    int flag=0;
    for(int i=0;i<n;i++){
      ll check = v[i];
      if(mods[check % (2*k)] == -1){
        flag=1;
        break;
      }
      else{
      mods[(check+k) % (2*k)] = -1;}
    }
    
    if(flag){
      cout << "-1" << endl;
    }
    else{ 
    int ans=v[n-1];
    int mod=0;
    while(!flag){
    flag =1;
    for(int i=0;i<n;i++){
          if((ans-v[i]) % (2*k) > k){
            flag =0;
            mod = v[i];
            ans++;
            break;
          } 
    }
        if(ans > (v[n-1]+2*k)){
          flag=1;
          ans = -1;
          break;
        }
    }
      if(flag){
        cout << ans << endl;
      }
    }
  }

}


