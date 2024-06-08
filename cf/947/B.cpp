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
    int flag =0;
    int k=v[0];
    int j;
    for(int i=1;i<n;i++){
      if(v[i] % k != 0){
        j=v[i];
        break;
      }
      if(i == n-1){
        flag=2;
        break;
      }
    }
    // cout << k << " " << j << endl;
    if(flag != 2){
    for(int i=2;i<n;i++){
      if((v[i] % k == 0) || (v[i] % j == 0)){
        continue;
      }
      else{
        flag = 1;
        break;
      }
      }
    }
    if(flag == 1){
      cout << "No" << endl;
    }
    else cout << "Yes" << endl;
  }

}


